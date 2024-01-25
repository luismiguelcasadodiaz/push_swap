/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_nmtp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:38:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/25 17:54:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_nmtp.c
   @brief pss_nmtp() returns how many nodes have a bigger idx than idx.

   @param[in] idx: the idx to know how many nodes has above.
   @param[in]   s: an ordered stack to look in.

   @return  node count above the teoretic position idx has in the stack.

   @details
   Loops the stack till finds idx counting visiting nodes.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
short	pss_nmtp(ssize_t idx, t_pss *one)
{
	t_nod	*node;
	ssize_t nodes;
	short	count;
	short	found;

	count = 0;
	found = 0;
	nodes = pss_size(one);
	node = one->top;
	while (nodes && !found)
	{
		count++;
		if ((one->sid < idx) && (idx < one->bid))
			found = ((node->idx > idx) && (idx > node->next->idx));
		else if (idx < one->sid)
			found = (node->idx == one->sid);
		else
			found = (node->idx == one->bid);
		node = node->next;
		nodes--;
	}
	if (one->bid < idx)
		return (count - 1);
	else
		return (count);
}
