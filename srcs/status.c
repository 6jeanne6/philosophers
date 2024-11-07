/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:17 by jewu              #+#    #+#             */
/*   Updated: 2024/11/07 17:36:36 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//time socrate will spend sleeping
void	sleeping(t_philo *socrate)
{
	if (death_flag(socrate))
		return ;
	block_print(socrate, "is sleeping", WHITE);
	chronos_usleep(socrate->time_to_sleep, socrate);
}

//socrate needs 2 forks when eating
//time it takes for socrate to eat
void	eating(t_philo *socrate)
{
	if (death_flag(socrate))
		return ;
	if (socrate->id % 2 == 0)
	{
		pick_up_left_fork(socrate);
		pick_up_right_fork(socrate);
	}
	else
	{
		pick_up_right_fork(socrate);
		pick_up_left_fork(socrate);
	}
	pthread_mutex_lock(&socrate->meal_lock);
	socrate->meals_eaten++;
	socrate->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&socrate->meal_lock);
	block_print(socrate, "is eating", GREEN);
	chronos_usleep(socrate->time_to_eat, socrate);
	put_down_fork(socrate);
}

//if fork not available socrate will think
//thiking time = eat - sleep
void	thinking(t_philo *socrate)
{
	long	time_to_think;

	if (death_flag(socrate))
		return ;
	time_to_think = socrate->time_to_eat - socrate->time_to_sleep;
	block_print(socrate, "is thinking", CYAN);
	chronos_usleep(time_to_think, socrate);
}
