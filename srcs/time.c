/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:49:35 by jewu              #+#    #+#             */
/*   Updated: 2024/11/07 15:17:13 by jewu             ###   ########.fr       */
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
	(void)socrate;
	usleep(wait_time * 1000);
	return (SUCCESS);
}
