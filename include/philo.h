/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:14:58 by jewu              #+#    #+#             */
/*   Updated: 2024/10/23 19:12:07 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/****** INCLUDES ******/

# include <string.h> 	//memset
# include <stdio.h> 	//printf
# include <stdlib.h> 	//malloc, free
# include <unistd.h> 	//write, usleep in microseconds
# include <sys/time.h> 	//gettimeofday in seconds and microseconds
# include <pthread.h> 	//pthread

// • pthread_create
//	→ create a new thread with specified function
// • pthread_detach
//	→ detach a thread when finished execution and free resources
// • pthread_join
//	→ waits for a specific thread to fetch its result/status
// • pthread_mutex_init
//	→ initiatlize a mutex (lock an instruction for one thread)
// • pthread_mutex_destroy
//	→ destroy an initialized mutex
// • pthread_mutex_lock
//	→ lock a mutex
// • pthread_mutex_unlock
//	→ unlock a mutex so that other threads can go

/****** DEFINE ******/

# define FAILURE 	-1
# define SUCCESS 	0

/****** COLORS ********/

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW 	"\033[0;33m"
# define BLUE 		"\033[0;34m"
# define PURPLE 	"\033[0;35m"
# define CYAN 		"\033[0;36m"
# define RESET 		"\033[0m"
# define WHITE      "\033[0;37m"

/****** STRUCTURES ******/

//philosophers structure
typedef struct s_philo
{
	pthread_t		thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dying_lock;

	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			countdown;

	int				id;
	int				nb_meals;
	int				meals_eaten;
	int				is_eating;
	int				died;

}				t_philo;

//supervisor : when 1 philo dies or minimum meal eaten, STOP
typedef struct s_manager
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dying_lock;

	t_philo			*philo;

	int				died;
	int				nb_of_philo;
}				t_manager;

/****** FUNCTIONS ******/

/* parsing */

int			parse_philo(int argc, char **argv);

/* initialization */

int			init_everything(char **argv, t_philo *philosopher);

/* routine */

void		*routine(void *philo);

/* utils */

int			ft_atoi(const char *nptr);

void		ft_bzero(void *s, size_t n);

long long	ft_atoll(const char *nptr);

/* error & free */

void		print_error_message(char *message);

#endif