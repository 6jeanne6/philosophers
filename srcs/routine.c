/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:16 by jewu              #+#    #+#             */
/*   Updated: 2024/11/12 15:07:16 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//put down left/right fork
//odd = taken left and right, put down right then left
void	put_down_fork(t_philo *socrate)
{
	if (socrate->id % 2 == 0)
	{
		pthread_mutex_unlock(&socrate->right_fork);
		pthread_mutex_unlock(socrate->left_fork);
	}
	else
	{
		pthread_mutex_unlock(socrate->left_fork);
		pthread_mutex_unlock(&socrate->right_fork);
	}
}

// thinking = recup des fourchettes
//eating = needs two forks to eat
//sleeping = put down forks
void	*routine(void *philo)
{
	t_philo	*socrate;

	socrate = (t_philo *)philo;
	pthread_mutex_lock(socrate->meal_lock);
	socrate->last_meal_time = socrate->start_time;
	pthread_mutex_unlock(socrate->meal_lock);
	while (!death_flag(socrate))
	{
		if (thinking(socrate) == FAILURE)
			break ;
		if (eating(socrate) == FAILURE)
			break ;
		if (sleeping(socrate) == FAILURE)
			break ;
	}
	return (NULL);
}
