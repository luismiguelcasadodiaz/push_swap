/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mkid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:40:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 12:25:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_mkid.c
   @brief pss_mkid() makes(calculates) the future positions in a sorted stack

   @param[in]  s: Non-empty stack to calculate value's future positions inside
   a hypotetical sorted stack.

   @details
   Loops the stack. For each node loops the stack couting how many values
   are lower or equal than current (external loop node) node's value.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_mkid(t_pss *s)
{
	t_nod	*ex_node;
	t_nod	*in_node;
	short	ex_end;
	short	in_end;

	if (pss_empt(s))
		return ;
	ex_end = 0;
	ex_node = s->top;
	while (!ex_end)
	{
		ex_end = (ex_node->next == s->top);
		in_end = 0;
		in_node = ex_node;
		while (!in_end)
		{
			in_end = (in_node->next == ex_node);
			if (in_node->num <= ex_node->num)
				ex_node->idx++;
			in_node = in_node->next;
		}
		ex_node = ex_node->next;
	}
	s->sid = pss_imin(s);
	s->bid = pss_imax(s);
}
