/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:17 by jewu              #+#    #+#             */
/*   Updated: 2024/11/26 10:56:49 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//time socrate will spend sleeping
int	sleeping(t_philo *socrate)
{
	if (death_flag(socrate))
		return (FAILURE);
	block_print(socrate, "is sleeping", WHITE);
	chronos_usleep(socrate->time_to_sleep, socrate);
	return (SUCCESS);
}

//socrate needs 2 forks when eating
//time it takes for socrate to eat
int	eating(t_philo *socrate)
{
	if (death_flag(socrate))
		return (put_down_fork(socrate), FAILURE);
	pthread_mutex_lock(socrate->last_meal_lock);
	socrate->last_meal_time = get_time_ms();
	pthread_mutex_unlock(socrate->last_meal_lock);
	block_print(socrate, "is eating", GREEN);
	chronos_usleep(socrate->time_to_eat, socrate);
	pthread_mutex_lock(socrate->meal_lock);
	socrate->meals_eaten++;
	pthread_mutex_unlock(socrate->meal_lock);
	put_down_fork(socrate);
	return (SUCCESS);
}

//odd philo thinks
static int	odd_socrate_thinking(t_philo *socrate, long think_time)
{
	if (death_flag(socrate))
		return (FAILURE);
	block_print(socrate, "is thinking", CYAN);
	chronos_usleep(think_time + 5, socrate);
	pthread_mutex_lock(&socrate->right_fork);
	block_print(socrate, "has taken a fork", YELLOW);
	if (death_flag(socrate) || socrate->nb_of_philo == 1)
		return (pthread_mutex_unlock(&socrate->right_fork), FAILURE);
	pthread_mutex_lock(socrate->left_fork);
	block_print(socrate, "has taken a fork", YELLOW);
	return (SUCCESS);
}

//even philo thinks
static int	even_socrate_thinking(t_philo *socrate, long think_time)
{
	if (death_flag(socrate))
		return (FAILURE);
	block_print(socrate, "is thinking", CYAN);
	if (socrate->first_meal == 0)
	{
		socrate->first_meal = 1;
		if (chronos_usleep(socrate->time_to_eat, socrate) == FAILURE)
			return (FAILURE);
	}
	else if (think_time)
		chronos_usleep(think_time, socrate);
	pthread_mutex_lock(socrate->left_fork);
	block_print(socrate, "has taken a fork", YELLOW);
	if (death_flag(socrate))
		return (pthread_mutex_unlock(socrate->left_fork), FAILURE);
	pthread_mutex_lock(&socrate->right_fork);
	block_print(socrate, "has taken a fork", YELLOW);
	return (SUCCESS);
}

//if fork not available socrate will think
//thiking time if number of philo is odd = eat - sleep
int	thinking(t_philo *socrate)
{
	long	time_to_think;

	time_to_think = 0;
	if (death_flag(socrate))
		return (FAILURE);
	if (socrate->nb_of_philo % 2 != 0
		&& socrate->time_to_eat > socrate->time_to_sleep)
			time_to_think = socrate->time_to_eat - socrate->time_to_sleep;
	if (socrate->id % 2 != 0)
	{
		if (odd_socrate_thinking(socrate, time_to_think) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (even_socrate_thinking(socrate, time_to_think) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
