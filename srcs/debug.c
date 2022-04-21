#include "philosophers.h"

void	print_philosophers(t_simulation *simulation)
{
	printf(""YELLOW"SIMULATION\n"YELLOW"");
	printf("number_of_philosophers = %i\n", simulation->number_of_philosophers);
	printf("time_to_die = %i\n", simulation->time_to_die);
	printf("time_to_eat = %i\n", simulation->time_to_eat);
	printf("time_to_sleep = %i\n", simulation->time_to_sleep);
	printf("number_of_time_each_philosophers_must_eat = %i\n", simulation->number_of_times_each_philosophers_must_eat);
	printf(""END_COLOR"");
}