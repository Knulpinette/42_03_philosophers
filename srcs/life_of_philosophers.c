/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2022/04/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live_life(void *newborn_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)newborn_philosopher;
	eating(philosopher);
	return (NULL);
}

void	eating(t_philosopher *philosopher)
{
	t_ms	took_fork;
	t_ms	started_eating;
	t_ms	eating_time;

	if (simulation_had_to_end(philosopher))
		return ;
	while (!philosopher->left_fork 
			|| philosopher->left_fork->taken == true
			|| philosopher->right_fork->taken == true)
	{
		if (simulation_had_to_end(philosopher))
			return ;
	}
	
	philosopher->left_fork->taken = true;
	philosopher->right_fork->taken = true;
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	took_fork = get_time_in_ms();
	print_life_state(philosopher, FORK, took_fork);
	print_life_state(philosopher, FORK, took_fork);

	started_eating = get_time_in_ms();
	eating_time = started_eating + philosopher->simulation->time_to_eat;
	print_life_state(philosopher, EAT, started_eating);
	philosopher->lifetime = started_eating + philosopher->simulation->time_to_die;
	if (philosopher->simulation->has_nb_of_meals)
		philosopher->nb_of_meals++;
	while (get_time_in_ms() <= eating_time)
		if (simulation_had_to_end(philosopher))
			return ;
	sleeping(philosopher);
}

void	sleeping(t_philosopher *philosopher)
{
	t_ms	started_sleeping;
	t_ms	nap_time;

	if (simulation_had_to_end(philosopher))
		return ;
	started_sleeping = get_time_in_ms();
	nap_time = started_sleeping + philosopher->simulation->time_to_sleep;
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	philosopher->left_fork->taken = false;
	philosopher->right_fork->taken = false;
	print_life_state(philosopher, SLEEP, started_sleeping);
	while (get_time_in_ms() <= nap_time)
	{
		if (simulation_had_to_end(philosopher))
			return ;
	}
	thinking(philosopher);
}

void	thinking(t_philosopher *philosopher)
{
	t_ms	started_thinking;

	if (simulation_had_to_end(philosopher))
		return ;
	started_thinking = get_time_in_ms();
	print_life_state(philosopher, THINK, started_thinking);
	eating(philosopher);
}
