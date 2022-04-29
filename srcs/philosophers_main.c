/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** 🦕
**
** philosophers
**
**	We need three types of structs:
**		1. Philosophers with all the personal infos.
**			(from which you can access the forks and
**				overall simulation)
**		2. Forks whose number is protected.
**		3. Simulation with all the shared infos.	
**
** 🦕
*/

static int	run_simulation(t_simulation *simulation, 
							t_fork *forks, t_philosopher *philosophers)
{
	pthread_t	*threads;
	int			i;

	threads = malloc_or_exit(sizeof(pthread_t), simulation->nb);
	i = 0;
	simulation->start_time = get_time_in_ms();
	while (i < simulation->nb)
	{
		philosophers[i].lifetime = simulation->start_time + simulation->time_to_die;
		if (pthread_create(threads + i, NULL, &live_life, (void *)&philosophers[i]))
			error_and_exit(THREAD_ERROR, threads);
		i++;
	}
	i = 0;
	while (i < simulation->nb)
	{
		if (pthread_join(threads[i], NULL))
			error_and_exit(THREAD_ERROR, threads);
		i++;
	}
	clean_the_table(threads, forks, simulation, philosophers);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_fork			*forks;
	t_philosopher	*philosophers;

	if (!argc || (argc < 5 || argc > 6))
		error_and_exit(WRONG_INPUT, NULL);
	simulation = get_simulation_parameters(argc, argv);
	forks = init_forks(simulation.nb);
	philosophers = init_philosophers(&simulation, forks);
	return (run_simulation(&simulation, forks, philosophers));
}
