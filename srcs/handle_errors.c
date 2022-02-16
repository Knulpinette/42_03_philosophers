/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:30:01 by osurcouf          #+#    #+#             */
/*   Updated: 2021/10/02 19:30:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    handle_error(t_errors error, t_philosophers *philosophers)
{
    (void)error;
    (void)philosophers;
    exit(EXIT_FAILURE);
}
