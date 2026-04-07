/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:22:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_args(t_data *data)
{
	if (data->num_coders <= 0 || data->time_to_burnout < 0
		|| data->time_to_compile < 0 || data->time_to_debug < 0
		|| data->time_to_refactor < 0 || data->dongle_cooldown < 0)
	{
		printf("Error: Arguments must be positive integers.\n");
		return (0);
	}
	return (1);
}

int	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac != 9)
		return (printf("Error: Invalid number of arguments.\n"), 0);
	i = 1;
	while (i <= 7)
	{
		if (!is_numeric(av[i]))
			return (printf("Error: Arguments must be numeric.\n"), 0);
		i++;
	}
	data->num_coders = ft_atoi(av[1]);
	data->time_to_burnout = ft_atoi(av[2]);
	data->time_to_compile = ft_atoi(av[3]);
	data->time_to_debug = ft_atoi(av[4]);
	data->time_to_refactor = ft_atoi(av[5]);
	data->num_compiles_required = ft_atoi(av[6]);
	data->dongle_cooldown = ft_atoi(av[7]);
	if (strcmp(av[8], "fifo") == 0)
		data->scheduler_type = POLICY_FIFO;
	else if (strcmp(av[8], "edf") == 0)
		data->scheduler_type = POLICY_EDF;
	else
		return (printf("Error: Scheduler must be 'fifo' or 'edf'.\n"), 0);
	return (validate_args(data));
}

static int	start_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->num_coders)
	{
		if (pthread_create(&data->coders[i].thread, NULL,
				&coder_routine, &data->coders[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(monitor, NULL, &monitor_routine, data) != 0)
		return (0);
	pthread_mutex_lock(&data->sim_mutex);
	data->start_time = get_time_ms();
	i = 0;
	while (i < data->num_coders)
	{
		data->coders[i].last_compile_start = data->start_time;
		i++;
	}
	pthread_mutex_unlock(&data->sim_mutex);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;
	pthread_t	monitor;

	memset(&data, 0, sizeof(t_data));
	if (!parse_args(ac, av, &data))
		return (1);
	if (!init_data(&data))
		return (cleanup_data(&data), 1);
	if (!start_threads(&data, &monitor))
		return (1);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data.num_coders)
	{
		pthread_join(data.coders[i].thread, NULL);
		i++;
	}
	cleanup_data(&data);
	return (0);
}
