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

void	*live_life(void *philosopher)
{
	(void)philosopher;
	return ((void *)"hello\n");
}

void	run_simulation(t_simulation *simulation, int nb_philosophers)
{
	pthread_t	*philosophers;
	int			i;

	philosophers = malloc(sizeof(pthread_t) * nb_philosophers);
	if (!philosophers)
		error_and_exit(FAIL_MALLOC, NULL);
	i = 0;
	while (i < nb_philosophers)
	{
		if (pthread_create(philosophers + i, NULL, &live_life, NULL)) //, (void *)lives_of_philosophers[i]);
			error_and_exit(THREAD_ERROR, NULL);
		i++;
	}
	i = 0;
	while (i < nb_philosophers)
	{
		if (pthread_join(philosophers[i], NULL))
			error_and_exit(THREAD_ERROR, NULL);
		i++;
	}
	free(philosophers);
	(void)simulation;
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (!argc || (argc < 5 || argc > 6))
		error_and_exit(WRONG_INPUT, NULL);
	simulation = get_simulation_parameters(argc, argv);
	run_simulation(&simulation, simulation.number_of_philosophers);
	print_philosophers(&simulation);
	return (EXIT_SUCCESS);
}
