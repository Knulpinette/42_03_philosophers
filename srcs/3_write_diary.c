/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_diary.c                                      :+:      :+:    :+:   */
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
** write_philosophers_diary
**
**	Here we write the status of all philosophers
**		> timestamp_in_ms  philosopher_ID  current_action
**
**	We have a print_mutex to garantee that everything get's written
**		in order even when actions are performed simulteanously.
**		We have also a bool "death_message_was_printed" to protect that
**		the last message printed will be the death of a philosopher even
**		if others are still doing things.
**
**	Philosophers->ID are shown as +1 to avoid having a Philosopher 0.
**	Timestamps are converting the current time in ms to the time since
**		beginning of simulation.
**
** 🦕
*/

void	write_in_diary(t_philosopher *philosopher, 
							t_life_action action, t_ms timestamp)
{
	if (philosopher->simulation->death_message_was_printed)
		return ;
	if (action == DIED && philosopher->simulation->has_ended)
		philosopher->simulation->death_message_was_printed = true;
	pthread_mutex_lock(&philosopher->simulation->print_mutex);
	timestamp = timestamp - philosopher->simulation->start_time;
	printf("%lli %i ", timestamp, philosopher->ID + 1);
	if (action == DIED)
		printf("died\n");
	else if (action == FORK)
		printf("has taken a fork\n");
	else if (action == EAT)
		printf("is eating\n");
	else if (action == SLEEP)
		printf("is sleeping\n");
	else if (action == THINK)
		printf("is thinking\n");
	pthread_mutex_unlock(&philosopher->simulation->print_mutex);
}
