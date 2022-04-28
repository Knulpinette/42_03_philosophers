#include "philosophers.h"

static bool	philosopher_has_died(t_philosopher *philosopher)
{
	t_ms	time_of_death;

	time_of_death = get_time_in_ms();
	if (philosopher->lifetime <= time_of_death)
	{
		philosopher->simulation->has_ended = true;
		print_life_state(philosopher, DIED, time_of_death);
		return (true);
	}
	return (false);
}

static bool	all_bellies_have_exploded(t_philosopher *philosopher)
{
	int	not_hungry_anymore;

	not_hungry_anymore = philosopher->simulation->nb_of_meals;
	if (philosopher->nb_of_meals > not_hungry_anymore) // here we need to go through an array of meals that would be in the simulation for sharing purposes.
		return (true);
	return (false);
}

bool	simulation_had_to_end(t_philosopher *philosopher)
{
	if (philosopher->simulation->has_ended)
		return (true);
	if (philosopher_has_died(philosopher))	
		return (true);
	if (philosopher->simulation->has_nb_of_meals)
		if (all_bellies_have_exploded(philosopher))
			return (true);
	//if (everyone_is_happy)
	return (false);
}
