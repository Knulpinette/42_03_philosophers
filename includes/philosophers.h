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

typedef long long	t_ms;

typedef struct s_simulation
{
	int				nb;
	t_ms			time_to_die;
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	bool			has_nb_of_meals;
	int				max_nb_of_meals;
	int				*nb_of_meals;
	t_ms			start_time;
	bool			has_ended;
	bool			death_message_was_printed;
	pthread_mutex_t	print_mutex;
}				t_simulation;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
	bool			taken;
}				t_fork;

typedef struct s_philosopher
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				nb_of_meals;
	t_ms			lifetime;
	t_simulation	*simulation;
}				t_philosopher;

/* ************************************************************************** */
/*							  table_setup	    			                  */
/* ************************************************************************** */

t_simulation	init_simulation(void);
t_simulation	get_simulation_parameters(int argc, char **argv);
t_fork			*init_forks(int nb_forks, t_simulation *simulation);
t_philosopher	*init_philosophers(t_simulation *simulation, t_fork *forks);

/* ************************************************************************** */
/*						 life_of_a_philosopher  			                  */
/* ************************************************************************** */

typedef enum e_life_action
{
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIED,
}				t_life_action;

void			*live_life(void *philosophers);
void			take_forks(t_philosopher *philosopher);
void			eating(t_philosopher *philosopher);
void			sleeping(t_philosopher *philosopher);
void			thinking(t_philosopher *philosopher);

/* ************************************************************************** */
/*								 write_diary  				                  */
/* ************************************************************************** */

void			write_in_diary(t_philosopher *philosopher,
					t_life_action action, t_ms timestamp);

/* ************************************************************************** */
/*						      the_afterlife  	  			                  */
/* ************************************************************************** */

bool			simulation_had_to_end(t_philosopher *philosopher);

/* ************************************************************************** */
/*								  utils		       			                  */
/* ************************************************************************** */

int				ft_atoi(const char *str);
bool			is_number(char *str);
t_ms			get_time_in_ms(void);
void			unlock_forks_and_return(t_philosopher *philosopher);

/* ************************************************************************** */
/*							  clean_the_table								  */
/* ************************************************************************** */

typedef enum e_errors
{
	ERROR = -1,
	NO_PRINT,
	WRONG_INPUT,
	FAIL_MALLOC,
	THREAD_ERROR,
}			t_errors;

void			clean_the_table(pthread_t *threads, t_fork *forks,
					t_simulation *simulation, t_philosopher *philosophers);
void			error_and_exit(t_errors err, t_fork *forks,
					t_simulation *simulation, t_philosopher *philosophers);
void			cleanup_threads_and_exit(pthread_t *threads, t_fork *forks,
					t_simulation *simulation, t_philosopher *philosophers);

#endif