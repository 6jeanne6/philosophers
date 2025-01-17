/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:38:02 by jewu              #+#    #+#             */
/*   Updated: 2024/11/08 16:34:48 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//after routine, free and clean everything
void	clean_everything(t_manager *zeus)
{
	int	i;

	i = -1;
	while (++i < zeus->nb_of_philo)
		pthread_mutex_destroy(&zeus->philo[i].right_fork);
	pthread_mutex_destroy(&zeus->write_lock);
	pthread_mutex_destroy(&zeus->dying_lock);
	pthread_mutex_destroy(&zeus->meal_lock);
	pthread_mutex_destroy(&zeus->last_meal_lock);
	pthread_mutex_destroy(&zeus->finish_eating_lock);
	free(zeus->philo);
	zeus->philo = NULL;
}

//customized message
void	print_error_message(char *message)
{
	if (!message)
		return ;
	printf(RED"%s"RESET, message);
}
