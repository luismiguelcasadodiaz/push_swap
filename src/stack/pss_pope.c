/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_pope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:31:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

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
	pss_mami(s, *num, 'o');
	nod_free(node);
	return (0);
}
