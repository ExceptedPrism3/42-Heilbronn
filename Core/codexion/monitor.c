/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:31:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	check_all_compiled(t_data *data)
{
	int	i;
	int	finished;

	if (data->num_compiles_required == -1)
		return (0);
	finished = 0;
	i = 0;
	while (i < data->num_coders)
	{
		pthread_mutex_lock(&data->sim_mutex);
		if (data->coders[i].compiles_done >= data->num_compiles_required)
			finished++;
		pthread_mutex_unlock(&data->sim_mutex);
		i++;
	}
	if (finished == data->num_coders)
	{
		pthread_mutex_lock(&data->sim_mutex);
		data->simulation_stopped = 1;
		pthread_mutex_unlock(&data->sim_mutex);
		return (1);
	}
	return (0);
}

static int	check_burnouts(t_data *data)
{
	int			i;
	long long	now;
	long long	last_start;

	i = 0;
	while (i < data->num_coders)
	{
		pthread_mutex_lock(&data->sim_mutex);
		last_start = data->coders[i].last_compile_start;
		now = get_time_ms();
		if (now - last_start >= data->time_to_burnout)
		{
			data->simulation_stopped = 1;
			pthread_mutex_unlock(&data->sim_mutex);
			print_log(&data->coders[i], "burned out");
			return (1);
		}
		pthread_mutex_unlock(&data->sim_mutex);
		i++;
	}
	return (0);
}

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

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	wait_ready(data);
	while (1)
	{
		if (check_burnouts(data) || check_all_compiled(data))
		{
			pthread_mutex_lock(&data->arbitrator_mutex);
			pthread_cond_broadcast(&data->arbitrator_cond);
			pthread_mutex_unlock(&data->arbitrator_mutex);
			break ;
		}
		pthread_mutex_lock(&data->arbitrator_mutex);
		pthread_cond_broadcast(&data->arbitrator_cond);
		pthread_mutex_unlock(&data->arbitrator_mutex);
		usleep(1000);
	}
	return (NULL);
}
