/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:38:02 by jewu              #+#    #+#             */
/*   Updated: 2024/10/14 14:06:15 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//customized message
void	print_error_message(char *message)
{
	if (!message)
		return ;
	printf(RED"%s"RESET, message);
}
