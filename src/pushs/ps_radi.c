/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:31:05 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 14:01:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* ps_radi() sorts stack a with radix sort algoritm                           */
/*                                                                            */
/* The position of the most significative bit of a's size determines how      */
/* many iterations needs radix algoritm.                                      */
/*                                                                            */
/* Sorts the pre-calculated positional indexes instead the values.            */
/*                                                                            */
/* in each iteration, pushes, from a to b, nodes with bit(n) = 0 and returns  */
/* them to stack a.                                                           */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
void	ps_radi(t_pss *a, t_pss *b)
{
	ssize_t	loops;
	ssize_t	bit;

	loops = ft_msb(pss_size(a));
	bit = 1;
	while (loops)
	{
		pss_prad(a, b, bit);
		pss_pall(a, b);
		pss_prnu(a);
		pss_prin(a);
		loops--;
		bit++;
	}
}
