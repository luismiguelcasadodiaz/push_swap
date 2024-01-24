/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_chea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/24 17:59:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include <limits.h>
#include "ft_printf.h"

static t_cost	optimize(t_pss *a, t_pss *b, ssize_t idx)
{
	t_cost	c;

	c.idx = idx; 
	pss_extr(pss_deep(idx, a), a, &c.dira, &c.mova);
	pss_inse(idx, b, &c.dirb, &c.movb);
	if ((c.dira == c.dirb) && (c.mova != 0) && (c.movb != 0))
	{
		if (c.mova > c.movb)
			c.mov = c.mova;
		else
			c.mov = c.movb; 
	}
	else
		c.mov = c.mova + c.movb;
	return (c);
}


t_cost	pss_chea(t_pss *a, t_pss *b)
{
	t_cost	c;
	t_cost cheaper;
	ssize_t	nodes;
	ssize_t	minmoves;
	t_nod	*node;

	minmoves = INT_MAX;
	nodes = pss_size(a);
	node = a->top;
	while (nodes)
	{
		c = optimize(a, b, node->idx);
		ft_printf("idx = %d, moves = %d\n", node->idx, c.mov);
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
