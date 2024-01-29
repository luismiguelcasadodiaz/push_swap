/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:46:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/30 00:24:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/******************************************************************************/
/**
   @file pss_turk.c
   @brief ps_turk() sorts stack a with Turkish algoritm.

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

 void	ps_turk(t_pss *a, t_pss *b)
 {
	t_cost	c;
	int i;

	i = pss_size(a);
	while (i > 3)
	{
		c = pss_chea(a, b);
		if (c.roro)
			pss_nror(a, b, c.roro);
		if (c.rrrr)
			pss_nrrr(a, b, c.rrrr);
		if (c.mova)
			pss_nrot(a, c.mova);
		if (c.rmva)
			pss_nrro(a, c.rmva);
		if (c.movb)
			pss_nrot(b, c.movb);
		if (c.rmvb)
			pss_nrro(b, c.rmvb);
		pss_psoo(b, a, PRINTME);
		i--;
	}
	ps_sor3(a);
	pss_ttop(b, b->bid);
	pss_movs(b, a);
	pss_ttop(a, a->sid);
 }
