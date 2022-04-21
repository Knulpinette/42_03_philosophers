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

void	*live_life(void *lives)
{
	(void)lives;
	return ((void *)"hello\n");
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