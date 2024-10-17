/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:25:22 by jewu              #+#    #+#             */
/*   Updated: 2024/10/17 18:19:18 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//main function of philo
int	main(int argc, char **argv)
{
	int	total_philo;

	if (parse_philo(argc, argv) == FAILURE)
		return (FAILURE);
	total_philo = ft_atoll(argv[1]);
	if (init_everything(argv) == SUCCESS)
	{
		printf("ca marche !\n");
	}
	return (SUCCESS);
}
