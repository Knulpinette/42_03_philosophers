#include "philosophers.h"

void	print_life_state(t_philosopher *philosopher, 
							t_life_action action, t_ms timestamp)
{
	if (philosopher->simulation->death_message_was_printed)
		return ;
	if (action == DIED && philosopher->simulation->has_ended)
		philosopher->simulation->death_message_was_printed = true;
	pthread_mutex_lock(&philosopher->simulation->print_mutex);
	timestamp = timestamp - philosopher->simulation->start_time;
	if (action == FORK)
		printf("%lli %i has taken a fork\n", timestamp, philosopher->ID);
	else if (action == EAT)
		printf("%lli %i is eating\n", timestamp, philosopher->ID);
	else if (action == SLEEP)
		printf("%lli %i is sleeping\n", timestamp, philosopher->ID);
	else if (action == THINK)
		printf("%lli %i is thinking\n", timestamp, philosopher->ID);
	else if (action == DIED)
		printf("%lli %i died\n", timestamp, philosopher->ID);
	pthread_mutex_unlock(&philosopher->simulation->print_mutex);
}