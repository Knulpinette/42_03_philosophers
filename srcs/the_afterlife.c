/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_afterlife.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2022/04/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philosopher_has_died(t_philosopher *philosopher)
{
	t_ms	time_of_death;

	time_of_death = get_time_in_ms();
	if (philosopher->lifetime <= time_of_death)
	{
		philosopher->simulation->has_ended = true;
		usleep(1000);
		write_in_diary(philosopher, DIED, time_of_death);
		return (true);
	}
	return (false);
}

static bool	all_bellies_have_exploded(t_philosopher *philosopher)
{
	int	not_hungry_anymore;
	int	i;

	not_hungry_anymore = philosopher->simulation->max_nb_of_meals;
	i = 0;
	while (i < philosopher->simulation->nb)
	{
		if (philosopher->simulation->nb_of_meals[i] < not_hungry_anymore)
			return (false);
		i++;
	}
	return (true);
}

bool	simulation_had_to_end(t_philosopher *philosopher)
{
	if (philosopher->simulation->has_ended)
		return (true);
	if (philosopher_has_died(philosopher))	
		return (true);
	if (philosopher->simulation->has_nb_of_meals 
			&& (philosopher->simulation->nb_of_meals[philosopher->ID] 
			>= philosopher->simulation->max_nb_of_meals))
	{
		if (all_bellies_have_exploded(philosopher))
			return (true);
	}
	return (false);
}
