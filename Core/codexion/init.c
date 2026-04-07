/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:32:20 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_dongles(t_data *data)
{
	int	i;

	data->dongles = malloc(sizeof(t_dongle) * data->num_coders);
	if (!data->dongles)
		return (0);
	i = 0;
	while (i < data->num_coders)
	{
		data->dongles[i].id = i;
		data->dongles[i].in_use = 0;
		data->dongles[i].available_at = 0;
		if (pthread_mutex_init(&data->dongles[i].lock, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	init_coders(t_data *data)
{
	int	i;

	data->coders = malloc(sizeof(t_coder) * data->num_coders);
	if (!data->coders)
		return (0);
	i = 0;
	while (i < data->num_coders)
	{
		data->coders[i].id = i + 1;
		data->coders[i].compiles_done = 0;
		data->coders[i].wants_to_compile = 0;
		data->coders[i].data = data;
		data->coders[i].left_dongle = &data->dongles[i];
		data->coders[i].right_dongle = &data->dongles[(i + 1)
			% data->num_coders];
		i++;
	}
	return (1);
}

int	init_data(t_data *data)
{
	data->simulation_stopped = 0;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->sim_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->arbitrator_mutex, NULL) != 0)
		return (0);
	if (pthread_cond_init(&data->arbitrator_cond, NULL) != 0)
		return (0);
	if (!init_dongles(data))
		return (0);
	if (!init_coders(data))
		return (0);
	return (1);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->dongles)
	{
		i = 0;
		while (i < data->num_coders)
		{
			pthread_mutex_destroy(&data->dongles[i].lock);
			i++;
		}
		free(data->dongles);
	}
	if (data->coders)
		free(data->coders);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->sim_mutex);
	pthread_mutex_destroy(&data->arbitrator_mutex);
	pthread_cond_destroy(&data->arbitrator_cond);
}
