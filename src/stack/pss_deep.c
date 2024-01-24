/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_deep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:38:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 12:20:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_deep.c
   @brief pss_deep() returns how many nodes visited to find idx.

   @param[in] idx: the idx to know how many nodes has above.
   @param[in]   s: The stack to calculate value's future positions.

   @return  node count above an existing (in stack) value. 0 otherwise.

   @details
   Loops the stack till finds idx counting visiting nodes.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
ssize_t	pss_deep(ssize_t idx, t_pss *one)
{
	t_nod	*node;
	ssize_t	nodes;
	ssize_t	count;
	short	found;

	count = 0;
	if (pss_empt(one))
		return (count);
	found = 0;
	nodes = pss_size(one);
	node = one->top;
	while (nodes && !found)
	{
		count++;
		found = (node->idx == idx);
		node = node->next;
		nodes--;
	}
	if (found)
		return (count);
	else
		return (0);
}
