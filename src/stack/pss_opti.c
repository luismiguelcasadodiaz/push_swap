/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_opti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:05 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 19:06:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_opti.c
   @brief pss_opti_loop_a() Filling c cost struct with movements data, required
   to put idx on top of Stack A

   @param[in]   a:The stack we want extract idx from.
   @param[in] idx:the index we want to transfer from A to B.
   @param[out]  c:Cost struct with mova & rmva movements amount and 'f'.

   @details
   Navigates stack A increasing c.mova while not find idx. "mova" represents
   the rotate movements. "rmva" represents the reverse rotate movements. it
   is the mova complementary in A'size base.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static void	pss_opti_loop_a(t_pss *a, ssize_t idx, t_cost *c)
{
	t_nod	*node;

	node = a->top;
	while (node->idx != idx)
	{
		c->mova++;
		node = node->next;
	}
	c->rmva = pss_size(a) - c->mova;
}

/******************************************************************************/
/**
   @file pss_opti.c
   @brief pss_opti_loop_b() Filling c cost struct with movements data, required
   to put on top and bottom of Stack B the values that embrace idx.

   @param[in]   a:The stack we want extract idx from.
   @param[in] idx:the index we want to transfer from A to B. 
   @param[out]  c:Cost struct with movb & rmvb movements amount and 'f'.

   @details

   For stack B as it is already descendant ordered two approaches available.

   When idx belong to [sid..bid] interval. We count the rotate movements
   required to place in the top and in the bottom the two nodes embracing
   idx ((node->prev->idx > idx) && (idx > node->idx)).

   When idx is outside [sid..bid] interval. it is a new min/max. We count
   the rotate movevemts required to place bid on stack's top.

   "movb" represents the rotate movements. "rmvb" represents the reverse
   rotate movements. it is the movb complementary in B'size base.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static void	pss_opti_loop_b(t_pss *b, ssize_t idx, t_cost *c)
{
	t_nod	*node;

	if ((b->sid < idx) && (idx < b->bid))
	{
		node = b->top;
		while (!((node->prev->idx > idx) && (idx > node->idx)))
		{
			c->movb++;
			node = node->next;
		}
	}
	if ((idx < b->sid) || (b->bid < idx))
	{
		node = b->top;
		while (node->idx != b->bid)
		{
			c->movb++;
			node = node->next;
		}
	}
	c->rmvb = pss_size(b) - c->movb;
}

/******************************************************************************/
/**
   @file pss_opti.c
   @brief pss_opti() calculates best combination of moves to transfer idx from
   stack a to stack b.

   @param[in]   a:The stack we want extract idx from.
   @param[in]   b:the stack we want to insert ordered idx into.
   @param[in] idx:the index we want to transfer from A to B. 

   @return a t_cost struct calculated with optimal movements instruction.

   @details
   Initializes a cost struct with all values to zero and two direction to 'f'.

   Loops A, filling cost struct with movements data.
   Loops B, filling cost struct with movements data.

   Navigates stack A increasing c.mova while not find idx. "mova" represents
   the rotate movements. "rmva" represents the reverse rotate movements. it
   is the mova complementary in A'size base.

   For stack B as it is already descendant ordered two approaches available.

   When idx belong to [sid..bid] interval. We count the rotate movements
   required to place in the top and in the bottom the two nodes embracing
   idx ((node->prev->idx > idx) && (idx > node->idx)).

   When idx is outside [sid..bid] interval. it is a new min/max. We count
   the rotate movevemts required to place bid on stack's top.

   "movb" represents the rotate movements. "rmvb" represents the reverse
   rotate movements. it is the movb complementary in B'size base.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
t_cost	pss_opti(t_pss *a, t_pss *b, ssize_t idx)
{
	t_cost	c;

	cos_init(&c);
	c.idx = idx;
	pss_opti_loop_a(a, idx, &c);
	pss_opti_loop_b(b, idx, &c);
	return (pss_calc(c));
}
