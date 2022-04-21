/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:56:57 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 18:56:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include "colors.h"

/* ************************************************************************** */
/*                              Philosophers                                  */
/* ************************************************************************** */

/*
• Each program should have the same options: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	◦ number_of_philosophers: is the number of philosophers and also the number
	of forks
	
	◦ time_to_die: is in milliseconds, if a philosopher doesn’t start eating
	’time_to_die’ milliseconds after starting his last meal or the beginning
	of the simulation, it dies

	◦ time_to_eat: is in milliseconds and is the time it takes for a
	philosopher to eat. During that time he will need to keep the two forks.

	◦ time_to_sleep: is in milliseconds and is the time the philosopher will
	spend sleeping.

	◦ number_of_times_each_philosopher_must_eat: argument is optional, if all
	philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
	simulation will stop. If not specified, the simulation will stop only at 
	the death of a philosopher.
*/

typedef struct s_simulation
{
    int	number_of_philosophers;
    int time_to_die;
    int	time_to_eat;
    int	time_to_sleep;
    int	number_of_times_each_philosophers_must_eat;
}               t_simulation;

// pthread_t		philosophers;
// pthread_mutex_t	forks;

/* ************************************************************************** */
/*							  Initialisation      			                  */
/* ************************************************************************** */

t_simulation	init_simulation(void);
t_simulation	get_simulation_parameters(int argc, char **argv);

/* ************************************************************************** */
/*								  Utils		       			                  */
/* ************************************************************************** */

int		ft_atoi(const char *str);
bool	is_number(char *str);

/* DEBUG */

void	print_philosophers(t_simulation *simulation);

/* ************************************************************************** */
/*								  Errors									  */
/* ************************************************************************** */

typedef enum e_errors
{
    ERROR = -1,
	NO_PRINT,
	WRONG_INPUT,
	FAIL_MALLOC,
	THREAD_ERROR,
}               t_errors;

void    error_and_exit(t_errors error, pthread_t *philosophers,
						t_simulation *result, pthread_mutex_t *forks);
void    error_message(int error);

#endif