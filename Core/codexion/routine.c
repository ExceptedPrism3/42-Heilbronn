/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:34:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	wait_ready(t_data *data)
{
	int	ready;

	ready = 0;
	while (!ready)
	{
		pthread_mutex_lock(&data->sim_mutex);
		if (data->start_time > 0)
			ready = 1;
		pthread_mutex_unlock(&data->sim_mutex);
		if (!ready)
			usleep(100);
	}
}

static int	compile_step(t_coder *c, t_data *data)
{
	arbitrator_wait_for_dongles(c);
	pthread_mutex_lock(&data->sim_mutex);
	if (data->simulation_stopped)
	{
		pthread_mutex_unlock(&data->sim_mutex);
		return (0);
	}
	c->last_compile_start = get_time_ms();
	pthread_mutex_unlock(&data->sim_mutex);
	print_log(c, "is compiling");
	sys_sleep_ms(data->time_to_compile, data);
	pthread_mutex_lock(&data->sim_mutex);
	c->compiles_done++;
	pthread_mutex_unlock(&data->sim_mutex);
	arbitrator_release_dongles(c);
	return (1);
}

static void	post_compile_steps(t_coder *c, t_data *data)
{
	print_log(c, "is debugging");
	sys_sleep_ms(data->time_to_debug, data);
	print_log(c, "is refactoring");
	sys_sleep_ms(data->time_to_refactor, data);
	usleep(50);
}

void	*coder_routine(void *arg)
{
	t_coder	*c;
	t_data	*data;

	c = (t_coder *)arg;
	data = c->data;
	wait_ready(data);
	if (c->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->sim_mutex);
		if (data->simulation_stopped)
		{
			pthread_mutex_unlock(&data->sim_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->sim_mutex);
		if (!compile_step(c, data))
			break ;
		post_compile_steps(c, data);
	}
	return (NULL);
}
