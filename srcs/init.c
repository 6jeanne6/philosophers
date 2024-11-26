/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:06 by jewu              #+#    #+#             */
/*   Updated: 2024/11/15 12:57:35 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_number_meals(t_philo *socrate, char **argv)
{
	if (argv[5])
		socrate->nb_meals = ft_atoi(argv[5]);
	else
		socrate->nb_meals = -1;
}

//prepare philosopher array in zeus
static void	init_philo_socrate(t_manager *zeus, char **argv)
{
	int	i;

	i = -1;
	while (++i < zeus->nb_of_philo)
	{
		zeus->philo[i].id = i + 1;
		zeus->philo[i].nb_of_philo = zeus->nb_of_philo;
		zeus->philo[i].start_time = zeus->start_time;
		zeus->philo[i].last_meal_time = zeus->start_time;
		zeus->philo[i].time_to_die = ft_atoi(argv[2]);
		zeus->philo[i].time_to_eat = ft_atoi(argv[3]);
		zeus->philo[i].time_to_sleep = ft_atoi(argv[4]);
		set_number_meals(&zeus->philo[i], argv);
		pthread_mutex_init(&zeus->philo[i].right_fork, NULL);
		if (i != 0)
			zeus->philo[i].left_fork = &zeus->philo[i - 1].right_fork;
		zeus->philo[i].write_lock = &zeus->write_lock;
		zeus->philo[i].dying_lock = &zeus->dying_lock;
		zeus->philo[i].meal_lock = &zeus->meal_lock;
		zeus->philo[i].last_meal_lock = &zeus->last_meal_lock;
		zeus->philo[i].finish_eating_lock = &zeus->finish_eating_lock;
	}
	zeus->philo[0].left_fork = &zeus->philo[i - 1].right_fork;
}

//init mutex aka lock for Socrate and Zeus
static void	init_mutex_zeus(t_manager *zeus)
{
	pthread_mutex_init(&zeus->write_lock, NULL);
	pthread_mutex_init(&zeus->dying_lock, NULL);
	pthread_mutex_init(&zeus->meal_lock, NULL);
	pthread_mutex_init(&zeus->last_meal_lock, NULL);
	pthread_mutex_init(&zeus->finish_eating_lock, NULL);
}

//wait a bit and launch supervisor to check if
//time exceeded death time or philo is full
static void	launch_philo(t_manager *zeus)
{
	int	i;

	i = -1;
	chronos_usleep(100, &zeus->philo[0]);
	while (1)
	{
		if (zeus_is_listening(zeus) == FAILURE
			|| socrate_full(zeus) == SUCCESS)
			break ;
	}
	while (++i < zeus->nb_of_philo)
		pthread_join(zeus->philo[i].thread, NULL);
}

//init philo and manager structure
int	init_everything(char **argv, t_manager *zeus)
{
	int	i;

	i = -1;
	init_mutex_zeus(zeus);
	zeus->philo = ft_calloc(zeus->nb_of_philo, sizeof(t_philo));
	if (!zeus->philo)
		return (print_error_message("Error of malloc\n"), FAILURE);
	zeus->start_time = get_time_ms();
	init_philo_socrate(zeus, argv);
	if (argv[5])
		zeus->nb_meals = ft_atoi(argv[5]);
	else
		zeus->nb_meals = -1;
	while (++i < zeus->nb_of_philo)
		pthread_create(&zeus->philo[i].thread, NULL, &routine, &zeus->philo[i]);
	launch_philo(zeus);
	return (SUCCESS);
}
