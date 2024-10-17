/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:51 by jewu              #+#    #+#             */
/*   Updated: 2024/10/17 17:27:17 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//check str[i] and if it's an INT overflow
static int	check_overflow_number(char *str)
{
	long long	nb_tmp;

	nb_tmp = ft_atoll(str);
	if (nb_tmp > 2147483647)
		return (FAILURE);
	else
		return (SUCCESS);
}

//check str[i] and its characters to check if it's a positive number
static int	ft_is_positive_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '+')
			i++;
		if (str[i] == '-')
			return (FAILURE);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

//check for each number if it's correct
static int	check_each_argument(char *str)
{
	if (ft_is_positive_number(str) == FAILURE)
	{
		print_error_message(RED"This is not a positive number\n"RESET);
		return (FAILURE);
	}
	if (check_overflow_number(str) == FAILURE)
	{
		print_error_message(RED"The number overflows\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

//general parsing function of philo
int	parse_philo(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		print_error_message(RED"Check your number of arguments\n"RESET);
		return (FAILURE);
	}
	while (argv[++i])
	{
		if (ft_atoll(argv[1]) == 0 || ft_atoll(argv[1]) > 199)
		{
			print_error_message(RED"Check your number of philosophers\n"RESET);
			return (FAILURE);
		}
		if (check_each_argument(argv[i]) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
