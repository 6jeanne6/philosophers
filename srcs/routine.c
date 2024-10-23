/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:16 by jewu              #+#    #+#             */
/*   Updated: 2024/10/23 19:16:19 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*socrate;

	socrate = (t_philo *)philo;
	printf("\n");
	printf(RED"[%d]: YOU HAVE BEEN CAPYBARA'D\n"RESET, socrate->id);
	printf(YELLOW"[%d]: MY CAPYBARA IS SO CUTE\n"RESET, socrate->id);
	printf(WHITE"[%d]: JORINE IS BEST CAPYBARA\n"RESET, socrate->id);
	printf(GREEN"[%d]: SHE WANTS TO BE WITH ZEANNE\n"RESET, socrate->id);
	printf(BLUE"[%d]: ZEANNE IS IN MARSEILLE\n"RESET, socrate->id);
	printf(PURPLE"[%d]: THEY WANNA SEE EACH OTHER\n"RESET, socrate->id);
	printf(CYAN"[%d]: PLEASE BE HAPPY TOGETHER\n"RESET, socrate->id);
	return (socrate);
}
