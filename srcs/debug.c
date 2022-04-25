#include "philosophers.h"

void	print_philosophers(t_simulation *simulation, t_philosopher *philosophers)
{
	int	i;
	printf(""YELLOW"SIMULATION\n");
	printf("number_of_philosophers = %i\n", simulation->nb);
	printf("time_to_die = %lli\n", simulation->time_to_die);
	printf("time_to_eat = %lli\n", simulation->time_to_eat);
	printf("time_to_sleep = %lli\n", simulation->time_to_sleep);
	if (simulation->has_nb_of_meals)
		printf("number_of_time_each_philosophers_must_eat = %i\n", simulation->nb_of_meals);
	printf(""END_COLOR"");
	
	i = 0;
	printf(""CYAN"PHILOSOPHERS\n");
	while (i < simulation->nb)
	{
		printf("philosopher.ID = %i\n", philosophers[i].ID);
		printf("left_fork = %i\n", philosophers[i].left_fork->ID);
		printf("right_fork = %i\n", philosophers[i].right_fork->ID);
		i++;
	}
	printf(""END_COLOR"");
}