/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:55:44 by jewu              #+#    #+#             */
/*   Updated: 2024/11/07 18:07:17 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//get if socrate is full
int	get_full_philo(t_philo *socrate)
{
	int	full_philo;

	pthread_mutex_lock(&socrate->meal_lock);
	full_philo = socrate->full;
	pthread_mutex_unlock(&socrate->meal_lock);
	return (full_philo);
}

//get number of meals eaten
int	get_meals_eaten(t_philo *socrate)
{
	int	meals_eaten;

	pthread_mutex_lock(&socrate->meal_lock);
	meals_eaten = socrate->meals_eaten;
	pthread_mutex_unlock(&socrate->meal_lock);
	return (meals_eaten);
}

long	when_last_meal(t_philo *socrate)
{
	long	last_meal;

	pthread_mutex_lock(&socrate->meal_lock);
	last_meal = socrate->last_meal_time;
	pthread_mutex_unlock(&socrate->meal_lock);
	return (last_meal);
}

//check if philo died to stop or continue simulation
int	death_flag(t_philo *socrate)
{
	int	rip;

	pthread_mutex_lock(&socrate->dying_lock);
	rip = socrate->died;
	pthread_mutex_unlock(&socrate->dying_lock);
	return (rip);
}
