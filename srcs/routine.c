/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:16 by jewu              #+#    #+#             */
/*   Updated: 2024/11/06 15:23:46 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//pick up left fork
void	pick_up_left_fork(t_philo *socrate)
{
	pthread_mutex_lock(socrate->left_fork);
	block_print(socrate, "has taken a fork", YELLOW);
}

//pick up left fork
void	pick_up_right_fork(t_philo *socrate)
{
	pthread_mutex_lock(&socrate->right_fork);
	block_print(socrate, "has taken a fork", YELLOW);
}

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
	socrate->died = 0;
	socrate->start_time = get_time_ms();
	while (!death_flag(socrate))
	{
		thinking(socrate);
		eating(socrate);
		sleeping(socrate);
	}
	return (socrate);
}
