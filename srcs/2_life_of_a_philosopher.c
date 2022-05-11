/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosophers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:56:46 by osurcouf          #+#    #+#             */
/*   Updated: 2022/04/02 18:56:47 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** 🦕
**
** life_of_philosopher
**
**	The philosopher lives his life
**	1. He will grab two forks
**	2. He will eat for a given amount of time
**	3. He will sleep for a given amount of time
**		and release the fork in the process
**	4. He will think
**		especially if there is an odd number of
**		philosophers around the table.
**	5. And then all over again until he dies or
**		the whole table is not hungry anymore!
**
**	To avoid using the clunky usleep and sleep
**	functions, we loop through get_time_in_ms().
**
** 🦕
*/

void	*live_life(void *newborn_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)newborn_philosopher;
	take_forks(philosopher);
	return (NULL);
}

/*
**	If there is only one philosopher, he will die since
**	he only has one fork.
**
**	While forks are taken on the sides, the philosopher
**	ends up stuck - and can't grab any fork.
**	It's important the print message is after so there is
**	no risk of two philosophers having an already taken fork.
*/

void	take_forks(t_philosopher *philosopher)
{
	t_ms	took_forks;

	if (simulation_had_to_end(philosopher))
		return ;
	while (!philosopher->left_fork
		|| (philosopher->left_fork->taken == true
			|| philosopher->right_fork->taken == true))
	{
		if (simulation_had_to_end(philosopher))
			return ;
	}
	philosopher->left_fork->taken = true;
	philosopher->right_fork->taken = true;
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	took_forks = get_time_in_ms();
	write_in_diary(philosopher, FORK, took_forks);
	write_in_diary(philosopher, FORK, took_forks);
	eating(philosopher);
}

void	eating(t_philosopher *philosopher)
{
	t_ms	started_eating;
	t_ms	eating_time;

	if (simulation_had_to_end(philosopher))
		return (unlock_forks_and_return(philosopher));
	started_eating = get_time_in_ms();
	write_in_diary(philosopher, EAT, started_eating);
	eating_time
		= started_eating + philosopher->simulation->time_to_eat;
	philosopher->lifetime
		= started_eating + philosopher->simulation->time_to_die;
	while (get_time_in_ms() < eating_time)
	{
		if (simulation_had_to_end(philosopher))
			return (unlock_forks_and_return(philosopher));
	}
	if (philosopher->simulation->has_nb_of_meals)
		philosopher->simulation->nb_of_meals[philosopher->id] += 1;
	sleeping(philosopher);
}

/*
** Forks have to be unlocked after the print_state or philosophers might take
**	someone else's forks before they start sleeping.
*/

void	sleeping(t_philosopher *philosopher)
{
	t_ms	started_sleeping;
	t_ms	nap_time;

	if (simulation_had_to_end(philosopher))
		return (unlock_forks_and_return(philosopher));
	started_sleeping = get_time_in_ms();
	write_in_diary(philosopher, SLEEP, started_sleeping);
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	philosopher->left_fork->taken = false;
	philosopher->right_fork->taken = false;
	nap_time = started_sleeping + philosopher->simulation->time_to_sleep;
	while (get_time_in_ms() < nap_time)
		if (simulation_had_to_end(philosopher))
			return ;
	thinking(philosopher);
}

/*
** A little mandatory time to think was added when the number of
** philosophers is odd to avoid race conditions.
**
**	@arievs explains it very well:
**
** When there's an odd number of philosophers, we need to make sure the one
**	who didn't eat the longest manages to grab the forks instead of another one.
**	Imagine the following: there's 5 philosophers; 1 and 3 eat; 2 and 4 eat; 5 
**	and either 1 or 3 should start eating now, but instead 1 and 3 start eating
**	again and 5 starves. In order to avoid this, a small mandatory thinking time
**	was added when the number of philosophers is odd. In this way, the ones who
**	just finished sleeping and started thinking will be in disadvantage in
**	comparison to those who are thinking the longest (and thus not eating
**	the longest).
**
** BUT that only works in time_to_eat and time_to_sleep are the same. If 
**	time_to_sleep is significantly smaller, that small mandatory thinking time
**	won't make a difference. So if time_to_sleep is smaller than time_to_eat,
**	my philosophers need to think for the difference between the two plus that
**	small buffer.
*/

void	thinking(t_philosopher *philosopher)
{
	t_ms	started_thinking;

	if (simulation_had_to_end(philosopher))
		return ;
	started_thinking = get_time_in_ms();
	write_in_diary(philosopher, THINK, started_thinking);
	if (philosopher->simulation->nb % 2 != 0)
	{
		if (philosopher->simulation->time_to_eat
			> philosopher->simulation->time_to_sleep)
			usleep((philosopher->simulation->time_to_eat
					- philosopher->simulation->time_to_sleep) * 1000);
		usleep(1000);
	}
	take_forks(philosopher);
}
