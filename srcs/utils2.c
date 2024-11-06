/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:50:39 by jewu              #+#    #+#             */
/*   Updated: 2024/11/06 16:57:49 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//zeus checks if all socrate ate nb_meals
int	socrate_full(t_manager *zeus)
{
	int	i;
	int	all_philo;

	i = -1;
	all_philo = 0;
	if (zeus->nb_meals == 0)
		return (SUCCESS);
	while (++i < zeus->nb_of_philo)
	{
		pthread_mutex_lock(&zeus->meal_lock);
		if (zeus->philo[i].meals_eaten < zeus->nb_meals)
		{
			pthread_mutex_unlock(&zeus->meal_lock);
			return (FAILURE);
		}
		pthread_mutex_unlock(&zeus->meal_lock);
	}
	return (SUCCESS);
}

// static int	i_died(t_philo *socrate)
// {
// 	int	died;

// 	died = 0;
// 	pthread_mutex_lock(&socrate->dying_lock);
// 	if (get_time_ms() - (long)socrate->last_meal_time
// 		>= (long)socrate->time_to_die)
// 	{
// 		socrate->died = 1;
// 		died = 1;
// 	}
// 	pthread_mutex_unlock(&socrate->dying_lock);
// 	return (died);
// }

//zeus checks if a socrate died
int	zeus_is_listening(t_manager *zeus)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	// while (++i < zeus->nb_of_philo)
	// {
	// 	if (i_died(&zeus->philo[i]))
	// 	{
	// 		pthread_mutex_lock(&zeus->dying_lock);
	// 		if (zeus->philo[i].died == 1)
	// 			block_print(&zeus->philo[i], "died", RED);
	// 		flag = 1;
	// 		pthread_mutex_unlock(&zeus->dying_lock);
	// 	}
	// }
	while (++i < zeus->nb_of_philo)
	{
		pthread_mutex_lock(&zeus->dying_lock);
		if (zeus->philo[i].died == 1)
			block_print(&zeus->philo[i], "died", RED);
		flag = 1;
		pthread_mutex_unlock(&zeus->dying_lock);
	}
	return (flag);
}