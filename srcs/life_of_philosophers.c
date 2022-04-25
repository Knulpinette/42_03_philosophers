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
	/*if (its_the_end())
		return ;
	take_right_fork()
	take_left_fork()
	(lock_mutexes)
	while (time_to_eat)
		wait;
	if (nb_of_times_philo_must_eat)
		nb_of_meals++;*/
	(void)philosopher;
	printf("Philosopher is eating\n");
	sleeping(philosopher);
}

void	sleeping(t_philosopher *philosopher)
{
	/*if (its_the_end())
		return ;
	while (time_to_sleep)
		wait;*/
	(void)philosopher;
	printf("Philosopher is sleeping\n");
	thinking(philosopher);
}

void	thinking(t_philosopher *philosopher)
{
	/*if (its_the_end())
		return ;
	while (not_able_to_eat)
		wait;*/
	(void)philosopher;
	printf("Philosopher is thinking\n");
	//eating(philosopher);
}


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