/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_pope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/26 10:38:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

int	pss_pope(t_pss *s, int *num)
{	
	t_nod	*p;
	t_nod	*n;
	t_nod	*node;

	if (pss_empt(s))
		return (-1);
	node = s->top;
	*num = node->num;
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
	pss_mami(s, *num, 'o');
	nod_free(node);
	return (0);
}
