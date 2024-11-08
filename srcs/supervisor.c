/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:50:39 by jewu              #+#    #+#             */
/*   Updated: 2024/11/08 17:18:10 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//when a philo died, kill all other philos if alive
static int	kill_all_philos(t_manager *zeus)
{
	int	i;

	i = -1;
	while (++i < zeus->nb_of_philo)
	{
		if ((death_flag(&zeus->philo[i]) == 0)
			|| (get_full_philo(&zeus->philo[i])) == zeus->nb_meals)
		{
			pthread_mutex_lock(&zeus->philo[i].dying_lock);
			zeus->philo[i].died = 1;
			pthread_mutex_unlock(&zeus->philo[i].dying_lock);
		}
	}
	return (1);
}

//zeus checks if all socrate ate nb_meals
int	socrate_full(t_manager *zeus)
{
	int	i;

	i = -1;
	if (zeus->nb_meals == 0)
		return (SUCCESS);
	if (zeus->nb_meals == -1)
		return (FAILURE);
	while (++i < zeus->nb_of_philo)
	{
		if (get_meals_eaten(&zeus->philo[i]) >= zeus->nb_meals)
		{
			kill_all_philos(zeus);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

//check if last meal is superior to time to eat
static int	check_time(t_philo *socrate)
{
	long	last_meal;

	last_meal = when_last_meal(socrate);
	if ((get_time_ms() - last_meal)
		>= (long)socrate->time_to_die)
	{
		pthread_mutex_lock(&socrate->dying_lock);
		socrate->died = 1;
		pthread_mutex_unlock(&socrate->dying_lock);
		return (1);
	}
	return (0);
}

//zeus checks if a socrate died
//si philo a tout manger ignore le time to die
int	zeus_is_listening(t_manager *zeus)
{
	int		i;

	i = -1;
	while (++i < zeus->nb_of_philo)
	{
		if (check_time(&zeus->philo[i]))
		{
			i = -1;
			while (++i < zeus->nb_of_philo)
			{
				if (zeus->nb_meals != 0)
					block_print(&zeus->philo[i], "died", RED);
				if (kill_all_philos(zeus) == 1)
					return (1);
			}
		}
	}
	return (0);
}
