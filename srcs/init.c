/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:06 by jewu              #+#    #+#             */
/*   Updated: 2024/10/17 18:28:26 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//init mutex aka lock for Socrate and Zeus
static void	init_mutex(t_philo *socrate, t_manager *zeus)
{
	pthread_mutex_init(socrate->left_fork, NULL);
	pthread_mutex_init(socrate->right_fork, NULL);
	pthread_mutex_init(socrate->write_lock, NULL);
	pthread_mutex_init(socrate->dying_lock, NULL);
	pthread_mutex_init(zeus->left_fork, NULL);
	pthread_mutex_init(zeus->right_fork, NULL);
	pthread_mutex_init(zeus->write_lock, NULL);
	pthread_mutex_init(zeus->dying_lock, NULL);

}

//init philo and manager structure
int	init_everything(char **argv)
{
	int			i;
	t_philo		socrate;
	t_manager	zeus;

	ft_bzero(&socrate, sizeof(t_philo));
	ft_bzero(&zeus, sizeof(t_manager));
	zeus.nb_of_philo = ft_atoi(argv[1]);
	socrate.time_to_die = ft_atoi(argv[2]);
	socrate.time_to_eat = ft_atoi(argv[3]);
	socrate.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		socrate.nb_meals = ft_atoi(argv[5]);
}
