/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:37:31 by msousa            #+#    #+#             */
/*   Updated: 2022/03/11 00:46:07 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	app_init(t_app *self, int argc, char **argv)
{
	self->count = ft_atoi(argv[0]);
	self->time_to_die = ft_atoi(argv[1]);
	self->time_to_eat = ft_atoi(argv[2]);
	self->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 5)
		self->times_must_eat = ft_atoi(argv[4]);
	else
		self->times_must_eat = 0;
	self->count_philos_already_eaten = 0;
	self->starttime = ft_timenow();
	self->printstop = FALSE;
	self->philo = (t_philo *)malloc(sizeof(t_philo) * self->count);
	if (!self->philo)
		return ;
	pthread_mutex_init(&self->m_timenow, NULL);
	pthread_mutex_init(&self->m_gameover, NULL);
	pthread_mutex_init(&self->m_writer, NULL);
	pthread_mutex_init(&self->m_death, NULL);
	pthread_mutex_init(&self->m_printstop, NULL);
	pthread_mutex_init(&self->m_count_philos_already_eaten, NULL);
}

static void	philos_init(t_app *self)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < self->count)
	{
		philo = self->philo + i;
		philo->self = self;
		philo->id = i + 1;
		philo->times_eaten = 0;
		philo->thread = (pthread_t *)malloc(sizeof(pthread_t));
		philo->fork_right = NULL;
		philo->starttime_eat = self->starttime;
		philo->thread_guard = NULL;
		pthread_mutex_init(&philo->m_times_eaten, NULL);
		pthread_mutex_init(&philo->fork_left, NULL);
		if (i == (self->count - 1))
			philo->fork_right = &self->philo->fork_left;
		else
			philo->fork_right = &(philo + 1)->fork_left;
		i++;
	}
}

static void	*times_eaten(void *data)
{
	t_app	*self;

	self = (t_app *)data;
	while (1)
	{
		pthread_mutex_lock(&self->m_count_philos_already_eaten);
		if (self->count_philos_already_eaten == self->count)
		{
			pthread_mutex_unlock(&self->m_count_philos_already_eaten);
			break ;
		}
		pthread_mutex_unlock(&self->m_count_philos_already_eaten);
	}
	printf("%d philosophers have eaten %d time(s)\n", self->count,
		self->times_must_eat);
	pthread_mutex_unlock(&self->m_gameover);
	return (NULL);
}

static void	threads_create(t_app *self)
{
	int		i;
	t_philo	*philo;

	pthread_mutex_lock(&self->m_gameover);
	if (self->times_must_eat)
	{
		pthread_create(&self->times_eaten, NULL, times_eaten, self);
		pthread_detach(self->times_eaten);
	}
	i = 0;
	while (i < self->count)
	{
		philo = self->philo + i;
		pthread_create(philo->thread, NULL, routine, philo);
		pthread_detach(*(philo->thread));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_app	self;
	int		i;
	t_bool	valid;

	valid = TRUE;
	if (argc != 5 && argc != 6)
		valid = FALSE;
	i = 1;
	while (i < argc)
		if (!ft_isnumber_u(argv[i++]))
			valid = FALSE;
	if (ft_atoi(argv[1]) == 0)
		valid = FALSE;
	if (valid)
	{
		app_init(&self, --argc, ++argv);
		philos_init(&self);
		threads_create(&self);
		pthread_mutex_lock(&self.m_gameover);
		ft_usleep(1000);
	}
	else
		printf("Error\n");
	return (0);
}
