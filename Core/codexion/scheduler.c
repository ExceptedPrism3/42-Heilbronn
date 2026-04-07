/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:42:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static t_coder	*get_highest_priority_coder(t_data *data)
{
	int			i;
	t_coder		*best;
	t_coder		*curr;
	long long	now;

	best = NULL;
	i = -1;
	now = get_time_ms();
	while (++i < data->num_coders)
	{
		curr = &data->coders[i];
		if (curr->wants_to_compile == 0
			|| curr->left_dongle->in_use || curr->right_dongle->in_use
			|| curr->left_dongle->available_at > now
			|| curr->right_dongle->available_at > now)
			continue ;
		if (!best || compare_priority(curr, best, data->scheduler_type))
			best = curr;
	}
	return (best);
}

static void	take_dongles(t_coder *c)
{
	pthread_mutex_lock(&c->left_dongle->lock);
	c->left_dongle->in_use = 1;
	print_log(c, "has taken a dongle");
	pthread_mutex_lock(&c->right_dongle->lock);
	c->right_dongle->in_use = 1;
	print_log(c, "has taken a dongle");
	c->wants_to_compile = 0;
}

static int	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->sim_mutex);
	if (data->simulation_stopped)
	{
		pthread_mutex_unlock(&data->sim_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->sim_mutex);
	return (0);
}

void	arbitrator_wait_for_dongles(t_coder *c)
{
	t_data	*data;
	int		granted;

	data = c->data;
	granted = 0;
	pthread_mutex_lock(&data->arbitrator_mutex);
	c->wants_to_compile = get_time_ms();
	while (!granted)
	{
		if (check_stop(data))
			break ;
		if (data->num_coders == 1)
			pthread_cond_wait(&data->arbitrator_cond, &data->arbitrator_mutex);
		else if (get_highest_priority_coder(data) == c)
		{
			take_dongles(c);
			granted = 1;
		}
		else
			pthread_cond_wait(&data->arbitrator_cond, &data->arbitrator_mutex);
	}
	pthread_mutex_unlock(&data->arbitrator_mutex);
}

void	arbitrator_release_dongles(t_coder *c)
{
	t_data		*data;
	long long	cooldown_time;

	data = c->data;
	pthread_mutex_lock(&data->arbitrator_mutex);
	cooldown_time = get_time_ms() + data->dongle_cooldown;
	c->left_dongle->available_at = cooldown_time;
	c->left_dongle->in_use = 0;
	pthread_mutex_unlock(&c->left_dongle->lock);
	c->right_dongle->available_at = cooldown_time;
	c->right_dongle->in_use = 0;
	pthread_mutex_unlock(&c->right_dongle->lock);
	pthread_cond_broadcast(&data->arbitrator_cond);
	pthread_mutex_unlock(&data->arbitrator_mutex);
}
