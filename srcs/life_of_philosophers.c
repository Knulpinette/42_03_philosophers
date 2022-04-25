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
	eat(philosopher);
	return (NULL);
}

void	eat(t_philosopher *philosopher)
{
	/*take_right_fork(philosopher_id)
	take_left_fork(philosopher_id + 1)
	while (time_to_eat)
		wait;
	if (nb_of_times_philo_must_eat)
		nb_of_meals++;
	sleep(philosopher);*/
	(void)philosopher;
	printf("Philosopher is eating\n");
}
/*void	sleep(t_philosopher *philosopher)
{
	while (time_to_sleep)
		wait;
	think(philosopher);
}
//void	think(t_philosopher *philosopher)
{
	while (not_able_to_eat)
		wait;
	eat(philosopher);
}
*/

/*
void	state_of_philosopher(p_thread *philosopher)
{
	printf("%i %i has taken a fork\n", timestamp_in_ms, philosopher->id->id);
	printf("%i %i is eating\n", timestamp_in_ms, philosopher->id);
	printf("%i %i is sleeping\n", timestamp_in_ms, philosopher->id);
	printf("%i %i is thinking\n", timestamp_in_ms, philosopher->id);
	printf("%i %i died\n", timestamp_in_ms, philosopher->id);
}
*/