/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_chea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 16:30:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include <limits.h>
#include "ft_printf.h"

/******************************************************************************/
/**
   @file pss_chea.c
   @brief pss_chea() returns the cheapest cost to move a node from stack a to b

   @param[in] a: a stack to extract a node from.
   @param[in] b: a stack to insert in, in order, the node.

   @returns a t_cost struct with best movement instructions 

   @details
   Set the Hyphotesis that minimun moves to change the node are INT_MAX

   Loops the stack getting the cost of moving the current node, and tracking the
   one that has the minimun cost in the actual stack's status.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
t_cost	pss_chea(t_pss *a, t_pss *b)
{
	t_cost	c;
	t_cost	cheaper;
	ssize_t	nodes;
	ssize_t	minmoves;
	t_nod	*node;

	minmoves = INT_MAX;
	nodes = pss_size(a);
	node = a->top;
	while (nodes)
	{
		c = pss_opti(a, b, node->idx);
		if (c.mov < minmoves)
		{
			minmoves = c.mov;
			cheaper = c;
		}
		node = node->next;
		nodes--;
	}
	return (cheaper);
}
