/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:16 by jewu              #+#    #+#             */
/*   Updated: 2024/11/05 13:09:48 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//check if philo died to stop or continue simulation
int	death_flag(t_philo *socrate)
{
	int	rip;

	pthread_mutex_lock(&socrate->dying_lock);
	rip = socrate->died;
	pthread_mutex_unlock(&socrate->dying_lock);
	return (rip);
}

//pick up left/right fork
static void	pick_up_fork(t_philo *socrate)
{
	if (socrate->id % 2 == 0)
	{
		pthread_mutex_lock(&socrate->left_fork);
		pthread_mutex_lock(&socrate->right_fork);
	}
	else
	{
		pthread_mutex_lock(&socrate->right_fork);
		pthread_mutex_lock(&socrate->left_fork);
	}
}

//put down left/right fork
static void	put_down_fork(t_philo *socrate)
{
	if (socrate->id % 2 == 0)
	{
		pthread_mutex_unlock(&socrate->left_fork);
		pthread_mutex_unlock(&socrate->right_fork);
	}
	else
	{
		pthread_mutex_unlock(&socrate->right_fork);
		pthread_mutex_unlock(&socrate->left_fork);
	}
}

// thinking = recup des fourchettes
//eating = needs two forks to eat
//sleeping = put down forks
void	*routine(void *philo)
{
	t_philo	*socrate;
	int		dead;

	socrate = (t_philo *)philo;
	dead = 0;
	socrate->start_time = get_time_ms();
	socrate->died = 0;
	while (!death_flag(socrate))
	{
		thinking(socrate);
		pick_up_fork(socrate);
		eating(socrate);
		put_down_fork(socrate);
		sleeping(socrate);
	}
	return (socrate);
}
