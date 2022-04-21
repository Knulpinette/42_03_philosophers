#include "philosophers.h"

t_simulation	init_simulation(void)
{
	t_simulation	simulation;

	simulation.number_of_philosophers = 0;
	simulation.time_to_die = 0;
	simulation.time_to_eat = 0;
	simulation.number_of_times_each_philosophers_must_eat = 0;
	return (simulation);
}

t_simulation	get_simulation_parameters(int argc, char **argv)
{
	t_simulation	simulation;
	int				i;

	i = 1;
	simulation = init_simulation();
	while (i < argc)
	{
		if (i == 1 && is_number(argv[i]))
			simulation.number_of_philosophers = ft_atoi(argv[i]);
		else if (i == 2 && is_number(argv[i]))
			simulation.time_to_die = ft_atoi(argv[i]);
		else if (i == 3 && is_number(argv[i]))
			simulation.time_to_eat = ft_atoi(argv[i]);
		else if (i == 4 && is_number(argv[i]))
			simulation.time_to_sleep = ft_atoi(argv[i]);
		else if (i == 5 && is_number(argv[i]))
			simulation.number_of_times_each_philosophers_must_eat = 
					ft_atoi(argv[i]);
		else
			error_and_exit(WRONG_INPUT, NULL, NULL, NULL);
		i++;
	}
	return (simulation);
}
