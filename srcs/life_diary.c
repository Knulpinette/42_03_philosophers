#include "philosophers.h"

void	print_life_state(t_philosopher *philosopher, 
							t_life_action action, t_ms timestamp)
{
	if (action == FORK)
		printf("%lli %i has taken a fork\n", timestamp, philosopher->ID);
	if (action == EAT)
		printf("%lli %i is eating\n", timestamp, philosopher->ID);
	if (action == SLEEP)
		printf("%lli %i is sleeping\n", timestamp, philosopher->ID);
	if (action == THINK)
		printf("%lli %i is thinking\n", timestamp, philosopher->ID);
	if (action == DIED)
		printf("%lli %i died\n", timestamp, philosopher->ID);
}