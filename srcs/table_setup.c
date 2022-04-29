/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_simulation	init_simulation(void)
{
	t_simulation	simulation;

	simulation.nb = 0;
	simulation.time_to_die = 0;
	simulation.time_to_eat = 0;
	simulation.has_nb_of_meals = false;
	simulation.nb_of_meals = 0;
	simulation.start_time = 0;
	pthread_mutex_init(&simulation.print_mutex, NULL);
	simulation.has_ended = false;
	simulation.death_message_was_printed = false;
	return (simulation);
}

static void		init_max_nb_meals(t_simulation *simulation, char *argv)
{
	int	j;

	j = 0;
	simulation->has_nb_of_meals = true;
	simulation->max_nb_of_meals = ft_atoi(argv);
	simulation->nb_of_meals = malloc_or_exit(sizeof(int), simulation->nb);
	j = 0;
	while (j < simulation->nb)
		simulation->nb_of_meals[j++] = 0;
}

t_simulation	get_simulation_parameters(int argc, char **argv)
{
	t_simulation	simulation;
	int				i;

	i = 1;
	simulation = init_simulation();
	while (i < argc)
	{
		if (i == 1 && is_number(argv[i]))
			simulation.nb = ft_atoi(argv[i]);
		else if (i == 2 && is_number(argv[i]))
			simulation.time_to_die = ft_atoi(argv[i]);
		else if (i == 3 && is_number(argv[i]))
			simulation.time_to_eat = ft_atoi(argv[i]);
		else if (i == 4 && is_number(argv[i]))
			simulation.time_to_sleep = ft_atoi(argv[i]);
		else if (i == 5 && is_number(argv[i]))
			init_max_nb_meals(&simulation, argv[i]);
		else
			error_and_exit(WRONG_INPUT, NULL);
		i++;
	}
	return (simulation);
}

t_fork	*init_forks(int nb_forks)
{
	t_fork	*forks;
	int		i;

	forks = malloc_or_exit(sizeof(t_fork), nb_forks);
	i = 0;
	while (i < nb_forks)
	{
		forks[i].ID = i;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].taken = false;
		i++;
	}
	return (forks);
}

t_philosopher	*init_philosophers(t_simulation *simulation, t_fork *forks)
{
	t_philosopher *philosophers;
	int				i;

	philosophers = malloc_or_exit(sizeof(t_philosopher), simulation->nb);
	i = 0;
	while (i < simulation->nb)
	{
		philosophers[i].ID = i;
		if (simulation->nb == 1)
			philosophers[i].left_fork = NULL;
		else if (i == simulation->nb - 1)
			philosophers[i].left_fork = &forks[0];
		else
			philosophers[i].left_fork = &forks[i + 1];
		philosophers[i].right_fork = &forks[i];
		philosophers[i].lifetime = 0;
		philosophers[i].simulation = simulation;
		i++;
	}
	return (philosophers);
}
