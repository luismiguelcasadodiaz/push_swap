/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_nmtp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:38:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 16:00:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_nmtp.c
   @brief pss_nmtp() returns how many nodes are bigger than idx..

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
	short	count;
	short	found;

	if (!pss_isor(one))
		return (-1);
	count = 0;
	if (pss_empt(one))
		return (count);
	found = 0;
	node = one->top;
	while ((node->next != one->top) && !found)
	{
		count++;
		found = (node->idx < idx);
		node = node->next;
	}
	if (found)
		return (count);
	else
		return (0);
}
