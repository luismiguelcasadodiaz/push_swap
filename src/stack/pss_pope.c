/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_pope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 11:51:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/******************************************************************************/
/**
   @file pss_pope.c
   @brief pss_pope() extracts num & idx from top stacks's node.

   @param[in]    s: The stack to push a node in.
   @param[out] num: The num the hode has to hold.
   @param{out] idx: The idx wiht the future position for the num.

   @details
   Removes a node that holds num and idx.
   
   Decreases stack size.
   Updates stack sma/sid or big/bidmax if num/idx is a new max or min.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/

int	pss_pope(t_pss *s, int *num, ssize_t *idx)
{
	t_nod	*p;
	t_nod	*n;
	t_nod	*node;

	if (pss_empt(s))
		return (-1);
	node = s->top;
	*num = node->num;
	*idx = node->idx;
	if (pss_size(s) > 1)
	{
		p = s->top->prev;
		n = s->top->next;
		p->next = n;
		n->prev = p;
		s->top = n;
	}
	else
		s->top = NULL;
	node->prev = NULL;
	node->next = NULL;
	s->siz = s->siz - 1;
	pss_mami(s, *num, *idx, 'o');
	nod_free(node);
	return (0);
}
