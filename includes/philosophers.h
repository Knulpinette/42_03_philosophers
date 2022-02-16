/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:56:57 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 18:56:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include "colors.h"

/* ************************************************************************** */
/*                              Philosophers                                  */
/* ************************************************************************** */

typedef struct s_philosophers
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosophers_must_eat;
}               t_philosophers;

/* ************************************************************************** */
/*								  Utils		       			                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*								  Errors									  */
/* ************************************************************************** */

typedef enum e_errors
{
    ERROR = -1,
}               t_errors;

void    handle_error(t_errors error, t_philosophers *philosophers);

#endif