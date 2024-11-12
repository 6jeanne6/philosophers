/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:49:35 by jewu              #+#    #+#             */
/*   Updated: 2024/11/11 18:28:40 by jewu             ###   ########.fr       */
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
int	chronos_usleep(long wait_time, t_philo *socrate)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < wait_time)
	{
		if (death_flag(socrate))
			return (FAILURE);
		usleep(100);
	}
	return (SUCCESS);
}
