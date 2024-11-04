/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:16 by jewu              #+#    #+#             */
/*   Updated: 2024/11/04 16:47:22 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//check if philo died to stop or continue simulation
static int	death_flag(t_philo *socrate)
{
	int	rip;

	pthread_mutex_lock(&socrate->dying_lock);
	rip = socrate->died;
	pthread_mutex_unlock(&socrate->dying_lock);
	return (rip);
}

// thinking = recup des fourchettes
// philo pair et philo impair
void	*routine(void *philo)
{
	t_philo	*socrate;
	int		dead;

	socrate = (t_philo *)philo;
	dead = 0;
	while (!death_flag(socrate))
	{
		thinking(socrate);
		sleeping(socrate);
		eating(socrate);
	}
	return (socrate);
}
