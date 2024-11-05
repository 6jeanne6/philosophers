/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:06 by jewu              #+#    #+#             */
/*   Updated: 2024/11/05 12:43:33 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//prepare philosopher array in zeus
static void	init_philo_socrate(t_manager *zeus, char **argv)
{
	int	i;

	i = -1;
	while (++i < zeus->nb_of_philo)
	{
		zeus->philo[i].id = i + 1;
		zeus->philo[i].time_to_die = ft_atoi(argv[2]);
		zeus->philo[i].time_to_eat = ft_atoi(argv[3]);
		zeus->philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			zeus->philo[i].nb_meals = ft_atoi(argv[5]);
		pthread_mutex_init(&zeus->philo[i].left_fork, NULL);
		pthread_mutex_init(&zeus->philo[i].right_fork, NULL);
		pthread_mutex_init(&zeus->philo[i].write_lock, NULL);
		pthread_mutex_init(&zeus->philo[i].dying_lock, NULL);
		pthread_create(&zeus->philo[i].thread, NULL, &routine, &zeus->philo[i]);
		pthread_join(zeus->philo[i].thread, NULL);
	}
}

//init mutex aka lock for Socrate and Zeus
static void	init_mutex_zeus(t_manager *zeus)
{
	pthread_mutex_init(&zeus->left_fork, NULL);
	pthread_mutex_init(&zeus->right_fork, NULL);
	pthread_mutex_init(&zeus->write_lock, NULL);
	pthread_mutex_init(&zeus->dying_lock, NULL);
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
	init_philo_socrate(zeus, argv);
	return (SUCCESS);
}
