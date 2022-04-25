#include "philosophers.h"

void	print_philosophers(t_simulation *simulation)
{
	printf(""YELLOW"SIMULATION\n"YELLOW"");
	printf("number_of_philosophers = %i\n", simulation->nb);
	printf("time_to_die = %lli\n", simulation->time_to_die);
	printf("time_to_eat = %lli\n", simulation->time_to_eat);
	printf("time_to_sleep = %lli\n", simulation->time_to_sleep);
	if (simulation->is_nb_of_meals)
		printf("number_of_time_each_philosophers_must_eat = %i\n", simulation->nb_of_meals);
	printf(""END_COLOR"");
}