/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:49:35 by jewu              #+#    #+#             */
/*   Updated: 2024/11/05 12:42:42 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//converts microseconds into millieseconds
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec) / 1000);
}

//get current time to be converted in millieseconds
int	chronos_usleep(unsigned long wait_time, t_philo *socrate)
{
	long	start_time;

	if (death_flag(socrate))
		return (FAILURE);
	start_time = get_time_ms();
	usleep(wait_time);
	return (SUCCESS);
}
