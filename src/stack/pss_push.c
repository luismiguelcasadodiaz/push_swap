/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 11:46:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/******************************************************************************/
/**
   @file pss_push.c
   @brief pss_push() inserts on top of the stack a node with NUM & idx

   @param[in]   s: The stack to push a node in.
   @param[in] num: The num the hode has to hold.
   @param{in] idx: The idx wiht the future position for the num.

   @details
   Creates a node to hold num and idx. Inserts the node on top of the stack.
   Undates de node pointers accordingly to if the stask is empty o has nodes.
   Increase stack size.
   Updates stack max and min if num is a new max or min.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	pss_push(t_pss *s, int num, ssize_t idx)
{
	t_nod	*n;

	n = nod_init(num, idx);
	if (!n)
		return (-1);
	if (pss_empt(s))
	{
		s->top = n;
		n->prev = s->top;
		n->next = s->top;
	}
	else
	{
		s->top->prev->next = n;
		n->next = s->top;
		n->prev = s->top->prev;
		s->top->prev = n;
		s->top = n;
	}
	s->siz = s->siz + 1;
	pss_mami(s, num, idx, 'u');
	return (0);
}
