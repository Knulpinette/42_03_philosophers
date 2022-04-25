/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	run_simulation(t_simulation *simulation, 
							t_fork *forks, t_philosopher *philosophers)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * simulation->nb);
	if (!threads)
		error_and_exit(FAIL_MALLOC, NULL, NULL, NULL, NULL);
	i = 0;
	while (i < simulation->nb)
	{
		if (pthread_create(threads + i, NULL, &live_life, NULL)) //, (void *)philosophers[i]);
			error_and_exit(THREAD_ERROR, threads, NULL, NULL, NULL);
		i++;
	}
	i = 0;
	while (i < simulation->nb)
	{
		if (pthread_join(threads[i], NULL))
			error_and_exit(THREAD_ERROR, threads, NULL, NULL, NULL);
		i++;
	}
	print_philosophers(simulation);
	clean_the_table(threads, forks, simulation, philosophers);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_fork			*forks;
	t_philosopher	*philosophers;

	if (!argc || (argc < 5 || argc > 6))
		error_and_exit(WRONG_INPUT, NULL, NULL, NULL, NULL);
	simulation = get_simulation_parameters(argc, argv);
	forks = init_forks(simulation.nb);
	philosophers = init_philosophers(&simulation, forks);
	run_simulation(&simulation, forks, philosophers);
	return (EXIT_SUCCESS);
}
