/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:25:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sys_sleep_ms(long long ms, t_data *data)
{
	long long	start;

	start = get_time_ms();
	while (get_time_ms() - start < ms)
	{
		pthread_mutex_lock(&data->sim_mutex);
		if (data->simulation_stopped)
		{
			pthread_mutex_unlock(&data->sim_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->sim_mutex);
		usleep(500);
	}
}

void	print_log(t_coder *coder, char *status)
{
	long long	timestamp;
	t_data		*data;

	data = coder->data;
	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->sim_mutex);
	if (!data->simulation_stopped || strcmp(status, "burned out") == 0)
	{
		timestamp = get_time_ms() - data->start_time;
		printf("%lld %d %s\n", timestamp, coder->id, status);
	}
	pthread_mutex_unlock(&data->sim_mutex);
	pthread_mutex_unlock(&data->print_mutex);
}

int	compare_priority(t_coder *c1, t_coder *c2, int sched_type)
{
	long long	start1;
	long long	start2;

	if (sched_type == POLICY_FIFO)
		return (c1->wants_to_compile < c2->wants_to_compile);
	else
	{
		start1 = c1->last_compile_start;
		start2 = c2->last_compile_start;
		if (start1 == start2)
			return (c1->id > c2->id);
		return (start1 < start2);
	}
}
