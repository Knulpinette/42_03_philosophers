/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:37:34 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:37:39 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** 🦕
**
** utils
**
** 1. utils to validate input
**		parsing if it's all numbers
**		and ft_atoi since we can't use the libft
**
**	2. utils to get the current time in ms
**
** 🦕
*/

bool	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	np;
	int	nbr;

	i = 0;
	nbr = 0;
	np = 1;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			np = np * -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * np);
}

t_ms	get_time_in_ms(void)
{
	struct timeval	now;
	t_ms			time_in_ms;

	gettimeofday(&now, NULL);
	time_in_ms = (t_ms)((now.tv_sec * 1000) + (now.tv_usec / 1000));
	return (time_in_ms);
}
