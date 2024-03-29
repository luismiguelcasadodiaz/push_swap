/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:31:05 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 11:32:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/**
   @file pss_radi.c
   @brief ps_radi() sorts stack a with radix sort algoritm.

   @param[in]  a: Non-empty stack to calculate value's future positions inside
   a hypotetical sorted stack.
   @param[in]  b: a stack to assist the sorting algorithm

   @details
   The position of the most significative bit of a's size determines how        
   many iterations needs radix algoritm.
   Sorts the pre-calculated positional indexes instead the values.
   in each iteration, pushes, from a to b, nodes with bit(n) = 0 and returns
   them to stack a.

   In each iteration there are more or less 1,5 * size of a movements.
   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
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
		loops--;
		bit++;
	}
}
