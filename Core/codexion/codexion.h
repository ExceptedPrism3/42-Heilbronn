/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:15:00 by aben-cad          #+#    #+#             */
/*   Updated: 2026/03/13 17:20:00 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define POLICY_FIFO 1
# define POLICY_EDF 2

typedef struct s_data	t_data;

typedef struct s_dongle
{
	int				id;
	pthread_mutex_t	lock;
	long long		available_at;
	int				in_use;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	pthread_t		thread;
	long long		last_compile_start;
	int				compiles_done;
	long long		wants_to_compile;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
	t_data			*data;
}	t_coder;

struct s_data
{
	int				num_coders;
	long long		time_to_burnout;
	long long		time_to_compile;
	long long		time_to_debug;
	long long		time_to_refactor;
	int				num_compiles_required;
	long long		dongle_cooldown;
	int				scheduler_type;
	long long		start_time;
	int				simulation_stopped;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	arbitrator_mutex;
	pthread_cond_t	arbitrator_cond;
	t_dongle		*dongles;
	t_coder			*coders;
};

/* Parsing and Utils */
int			parse_args(int ac, char **av, t_data *data);
long long	get_time_ms(void);
void		sys_sleep_ms(long long ms, t_data *data);
void		print_log(t_coder *coder, char *status);
int			ft_atoi(const char *str);

/* Scheduler functions */
int			compare_priority(t_coder *c1, t_coder *c2, int sched_type);

/* Initialization and Cleanup */
int			init_data(t_data *data);
void		cleanup_data(t_data *data);

/* Core Logic */
void		*coder_routine(void *arg);
void		*monitor_routine(void *arg);

/* Scheduler */
void		arbitrator_wait_for_dongles(t_coder *c);
void		arbitrator_release_dongles(t_coder *c);

#endif
