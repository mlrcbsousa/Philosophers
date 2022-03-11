/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:38:05 by msousa            #+#    #+#             */
/*   Updated: 2022/03/11 00:42:05 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

# include "lib.h"

// Enums
typedef enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK
}	t_state;

// Structs
typedef struct s_app	t_app;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_app			*self;
	int				id;
	int				times_eaten;
	long			starttime_eat;
	pthread_t		*thread;
	pthread_t		*thread_guard;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	m_times_eaten;
};

struct s_app {
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				count_philos_already_eaten;
	long			starttime;
	t_bool			printstop;
	t_philo			*philo;
	pthread_mutex_t	m_writer;
	pthread_mutex_t	m_gameover;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_timenow;
	pthread_mutex_t	m_printstop;
	pthread_mutex_t	m_count_philos_already_eaten;
	pthread_t		times_eaten;
};

// Functions
void	*routine(void *data);

#endif
