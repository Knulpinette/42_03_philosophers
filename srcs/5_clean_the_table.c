/* ************************************************************************** */
/*	       	                                                                  */
/*                                                        :::      ::::::::   */
/*   clean_the_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:30:01 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 19:30:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** 🦕
**
** clean_the_table
**
**	Here we handle all errors and exit processes.
**
**	1. Clean_the_table frees all the structs
**	2. Error_and_exit handles the errors.
**
** 🦕
*/

static void	print_instruction(void)
{
	printf("\n🦕🍭	"YELLOW"To use philosophers"END_COLOR"\n");
	printf("	./philosophers ");
	printf(""LIGHT_GRAY"number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	printf(""END_COLOR"");
	printf(""BOLDGRAY"		Times should be written in millisecond.\n");
	printf("		Do NOT test with more than 200 philosophers\n");
	printf("		Do NOT test with a time inferior to 60ms\n");
	printf("\n");
}

static void	error_message(int error)
{
	if (error == NO_PRINT)
		return ;
	printf(""RED"Error\n"END_COLOR"");
	if (error == WRONG_INPUT)
	{
		printf("RTFM, young padawan! You wrote the arguments wrong...\n");
		print_instruction();
	}
	if (error == THREAD_ERROR)
		printf("Failure to thread\n");
	if (error == FAIL_MALLOC)
		printf("Failure to allocate memory\n");
}

void	clean_the_table(pthread_t *threads, t_fork *forks,
						t_simulation *simulation, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	if (threads)
		free(threads);
	if (philosophers)
		free(philosophers);
	if (forks)
	{
		while (i < simulation->nb)
			pthread_mutex_destroy(&(forks[i++].mutex));
		free(forks);
	}
	if (simulation)
	{
		pthread_mutex_destroy(&simulation->print_mutex);
		if (simulation->has_nb_of_meals)
			free(simulation->nb_of_meals);
	}
}

void	error_and_exit(t_errors error, t_fork *forks,
						t_simulation *simulation, t_philosopher *philosophers)
{
	clean_the_table(NULL, forks, simulation, philosophers);
	error_message(error);
	exit(EXIT_FAILURE);
}

void	cleanup_threads_and_exit(pthread_t *threads, t_fork *forks,
						t_simulation *simulation, t_philosopher *philosophers)
{
	clean_the_table(threads, forks, simulation, philosophers);
	error_message(THREAD_ERROR);
	exit(EXIT_FAILURE);
}
