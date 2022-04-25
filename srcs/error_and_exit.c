/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:30:01 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 19:30:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void print_instruction(void)
{
    printf("    📚 "PURPLE"INSTRUCTIONS"END_COLOR"  📚\n");
	printf("\n🦕🍭	"YELLOW"To use philosophers"END_COLOR"\n");
    printf("	./philosophers ");
	printf(""LIGHT_GRAY"number_of_philosophers time_to_die time_to_eat");
    printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
    printf(""END_COLOR"");
    printf(""BOLDGRAY"        Times should be written in millisecond.\n");
    printf("        Do NOT test with more than 200 philosophers\n");
    printf("        Do NOT test with a time inferior to 60ms\n");
    printf("\n");
}

static void    error_message(int error)
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

void    error_and_exit(t_errors error, pthread_t *threads, 
                        t_philosopher *philosophers, pthread_mutex_t *forks)
{
     if (threads)
	 	free(threads);
    if (philosophers)
		free(philosophers);
    if (forks)
		free(forks);
	error_message(error);
	exit(EXIT_FAILURE);
}
