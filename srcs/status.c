/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:17 by jewu              #+#    #+#             */
/*   Updated: 2024/11/05 12:55:47 by jewu             ###   ########.fr       */
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

//time socrate will spend sleeping
void	sleeping(t_philo *socrate)
{
	if (death_flag(socrate))
		return ;
	block_print(socrate, "is sleeping", WHITE);
}

//socrate needs 2 forks when eating
//time it takes for socrate to eat
void	eating(t_philo *socrate)
{
	if (death_flag(socrate))
		return ;
	block_print(socrate, "is eating", GREEN);
}

//if fork not available socrate will think
void	thinking(t_philo *socrate)
{
	if (death_flag(socrate))
		return ;
	block_print(socrate, "is thinking", CYAN);
	chronos_usleep(100 * 1000, socrate);
}
