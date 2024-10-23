/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:25:22 by jewu              #+#    #+#             */
/*   Updated: 2024/10/23 18:47:31 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//main function of philo
int	main(int argc, char **argv)
{
	int		total_philo;
	t_philo	*socrate;

	if (parse_philo(argc, argv) == FAILURE)
		return (FAILURE);
	total_philo = ft_atoll(argv[1]);
	socrate = malloc(sizeof(t_philo) * (total_philo + 1));
	if (!socrate)
		return (FAILURE);
	if (init_everything(argv, socrate) == SUCCESS)
	{
		printf("ca marche !\n");
	}
	return (SUCCESS);
}
