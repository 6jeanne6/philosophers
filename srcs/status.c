/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:17 by jewu              #+#    #+#             */
/*   Updated: 2024/11/04 17:04:40 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if socrate did not eat time_to_die ms since the beginning of last meal
//or beginning of routine then they die
void	dying(t_philo *socrate)
{
	pthread_mutex_lock(&socrate->dying_lock);
	socrate->died = 1;
	printf(RED"%d died\n"RESET, socrate->id);
	pthread_mutex_unlock(&socrate->dying_lock);
}

//if fork not available socrate will think
void	thinking(t_philo *socrate)
{
	pthread_mutex_lock(&socrate->write_lock);
	printf(CYAN"%d is thinking\n"RESET, socrate->id);
	pthread_mutex_unlock(&socrate->write_lock);
}

//time socrate will spend sleeping
void	sleeping(t_philo *socrate)
{
	pthread_mutex_lock(&socrate->write_lock);
	printf(WHITE"%d is sleeping\n"RESET, socrate->id);
	pthread_mutex_unlock(&socrate->write_lock);
}

//socrate needs 2 forks when eating
//time it takes for socrate to eat
void	eating(t_philo *socrate)
{
	pthread_mutex_lock(&socrate->write_lock);
	printf(GREEN"%d is eating\n"RESET, socrate->id);
	pthread_mutex_unlock(&socrate->write_lock);
}
