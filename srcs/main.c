/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:25:22 by jewu              #+#    #+#             */
/*   Updated: 2024/10/21 17:45:37 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//main function of philo
int	main(int argc, char **argv)
{
	int		total_philo;
	t_philo	*philosopher;

	if (parse_philo(argc, argv) == FAILURE)
		return (FAILURE);
	total_philo = ft_atoll(argv[1]);
	philosopher = malloc(sizeof(t_philo) * (total_philo + 1));
	if (!philosopher)
		return (FAILURE);
	if (init_everything(argv, philosopher) == SUCCESS)
	{
		printf("ca marche !\n");
	}
	return (SUCCESS);
}
