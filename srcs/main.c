/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:25:22 by jewu              #+#    #+#             */
/*   Updated: 2024/11/07 12:29:11 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//main function of philo
int	main(int argc, char **argv)
{
	int			total_philo;
	t_manager	zeus;

	if (parse_philo(argc, argv) == FAILURE)
		return (FAILURE);
	total_philo = ft_atoi(argv[1]);
	ft_bzero(&zeus, sizeof(t_manager));
	zeus.nb_of_philo = total_philo;
	if (init_everything(argv, &zeus) == SUCCESS)
	{
		clean_everything(&zeus);
	}
	return (SUCCESS);
}
