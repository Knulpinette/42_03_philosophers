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
	printf("%lli %i ", timestamp, philosopher->ID + 1);
	if (action == FORK)
		printf("has taken a fork\n");
	else if (action == EAT)
		printf("is eating\n");
	else if (action == SLEEP)
		printf("is sleeping\n");
	else if (action == THINK)
		printf("is thinking\n");
	else if (action == DIED)
		printf("died\n");
	pthread_mutex_unlock(&philosopher->simulation->print_mutex);
}