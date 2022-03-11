/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:37:39 by msousa            #+#    #+#             */
/*   Updated: 2022/03/11 00:47:17 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_state_change(t_philo *philo, t_state state)
{
	t_app		*self;
	static char	*logs[5] = {
	"has taken a fork",
	"is eating",
	"is sleeping",
	"is thinking",
	};

	self = philo->self;
	pthread_mutex_lock(&self->m_writer);
	pthread_mutex_lock(&self->m_printstop);
	if (!self->printstop)
		printf("%ld %d %s\n", ft_timenow() - self->starttime, philo->id,
			logs[state]);
	pthread_mutex_unlock(&self->m_printstop);
	pthread_mutex_unlock(&self->m_writer);
}

static void	die(t_app *self, t_philo *philo)
{
	pthread_mutex_unlock(&self->m_timenow);
	pthread_mutex_lock(&self->m_death);
	pthread_mutex_lock(&self->m_printstop);
	self->printstop = TRUE;
	pthread_mutex_unlock(&self->m_printstop);
	pthread_mutex_lock(&self->m_writer);
	printf("%ld %d died\n", ft_timenow() - self->starttime, philo->id);
	pthread_mutex_unlock(&self->m_gameover);
	pthread_detach(*philo->thread_guard);
	pthread_detach(*philo->thread);
}

static void	eat_sleep_think(t_app *self, t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	log_state_change(philo, FORK);
	pthread_mutex_lock(philo->fork_right);
	log_state_change(philo, FORK);
	log_state_change(philo, EAT);
	pthread_mutex_lock(&self->m_timenow);
	philo->starttime_eat = ft_timenow();
	pthread_mutex_unlock(&self->m_timenow);
	ft_usleep(self->time_to_eat);
	pthread_mutex_lock(&philo->m_times_eaten);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->m_times_eaten);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	log_state_change(philo, SLEEP);
	ft_usleep(self->time_to_sleep);
	log_state_change(philo, THINK);
}

static void	*routine_guard(void *data)
{
	t_philo	*philo;
	t_app	*self;

	philo = (t_philo *)data;
	self = philo->self;
	while (1)
	{
		pthread_mutex_lock(&philo->m_times_eaten);
		if (self->times_must_eat
			&& (philo->times_eaten >= self->times_must_eat))
		{
			pthread_mutex_unlock(&philo->m_times_eaten);
			pthread_detach(*philo->thread);
			pthread_detach(*philo->thread_guard);
			break ;
		}
		pthread_mutex_unlock(&philo->m_times_eaten);
		pthread_mutex_lock(&self->m_timenow);
		if (philo->starttime_eat + self->time_to_die <= ft_timenow())
			die(self, philo);
		pthread_mutex_unlock(&self->m_timenow);
	}
	return (NULL);
}

void	*routine(void *data)
{
	t_philo		*philo;
	t_app		*self;
	pthread_t	guard;

	philo = (t_philo *)data;
	self = philo->self;
	if (philo->id % 2)
		ft_usleep(self->time_to_eat / 10);
	philo->thread_guard = &guard;
	pthread_create(&guard, NULL, routine_guard, philo);
	while (1)
	{
		if (self->times_must_eat
			&& (philo->times_eaten == self->times_must_eat))
		{
			pthread_mutex_lock(&self->m_count_philos_already_eaten);
			self->count_philos_already_eaten++;
			pthread_mutex_unlock(&self->m_count_philos_already_eaten);
			break ;
		}
		eat_sleep_think(self, philo);
	}
	return (NULL);
}
