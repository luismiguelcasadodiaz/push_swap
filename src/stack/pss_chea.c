/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_chea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:18:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/26 21:08:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include <limits.h>
#include "ft_printf.h"

// case 1 : rota a & rota b
static t_cost case1(t_cost c)
{
	if ((c.mova > c.movb) && (c.movb > 0))
	{
		c.roro = c.movb;
		c.mova = c.mova - c.movb;
		c.movb = 0;
	}
	if ((c.movb >= c.mova) && (c.mova > 0))
	{
		c.roro = c.mova;
		c.movb = c.movb - c.mova;
		c.mova = 0;
	}
	c.mov = c.roro + c.mova + c.movb;
	c.rmva = 0; 
	c.rmvb = 0;
	return (c);
}
// case 2 : rota a & rrot b
static t_cost case2(t_cost c)
{
	c.roro = 0;
	c.rrrr = 0;
	c.movb = 0;
	c.rmva = 0;
	c.mov = c.mova + c.rmvb;
	return (c);
}
// case 3 : rrot a & rota b
static t_cost case3(t_cost c)
{
	c.roro = 0;
	c.rrrr = 0;
	c.rmvb = 0;
	c.mova = 0;
	c.mov = c.rmva + c.movb;
	return (c);
}

// case 4 : rrot a & rrot b
static t_cost case4(t_cost c)
{
	if ((c.rmva > c.rmvb) && (c.rmvb > 0))
	{
		c.rrrr = c.rmvb;
		c.rmva = c.rmva - c.rmvb;
		c.rmvb = 0;
	}
	if ((c.rmvb >= c.rmva) && (c.rmva > 0))
	{
		c.rrrr = c.rmva;
		c.rmvb = c.rmvb -c.rmva;
		c.rmva = 0;
	}
	c.mov = c.rrrr + c.rmva + c.rmvb;
	c.mova = 0;
	c.movb = 0;
	return (c);
}

static t_cost	calculate(t_cost c)
{
	t_cost	option[4];
	short	i;
	short 	imin;
	short	min;
	t_cost	s;

	s = c;
	ft_printf("c0{idx:%d, mov:%d, mova:%d, rmva:%d, movb:%d, rmvb:%d, roro:%d, rrrr:%d}\n", s.idx, s.mov, s.mova, s.rmva, s.movb, s.rmvb, s.roro, s.rrrr);
	s = case1(c);
	ft_printf("c1{idx:%d, mov:%d, mova:%d, rmva:%d, movb:%d, rmvb:%d, roro:%d, rrrr:%d}\n", s.idx, s.mov, s.mova, s.rmva, s.movb, s.rmvb, s.roro, s.rrrr);
	s = case2(c);
	ft_printf("c2{idx:%d, mov:%d, mova:%d, rmva:%d, movb:%d, rmvb:%d, roro:%d, rrrr:%d}\n", s.idx, s.mov, s.mova, s.rmva, s.movb, s.rmvb, s.roro, s.rrrr);
	s = case3(c);
	ft_printf("c3{idx:%d, mov:%d, mova:%d, rmva:%d, movb:%d, rmvb:%d, roro:%d, rrrr:%d}\n", s.idx, s.mov, s.mova, s.rmva, s.movb, s.rmvb, s.roro, s.rrrr);
	s = case4(c);
	ft_printf("c4{idx:%d, mov:%d, mova:%d, rmva:%d, movb:%d, rmvb:%d, roro:%d, rrrr:%d}\n", s.idx, s.mov, s.mova, s.rmva, s.movb, s.rmvb, s.roro, s.rrrr);
	option[0] = case1(c);
	option[1] = case2(c);
	option[2] = case3(c);
	option[3] = case4(c);
	min = SHRT_MAX;
	i = 0;
	imin = 0;
	while (i < 4)
	{
		if (option[i].mov < min)
		{
			imin = i;
			min = option[i].mov;
		}
		i++;
	}
	return (option[imin]);
}

static t_cost	optimize2(t_pss *a, t_pss *b, ssize_t idx)
{
	t_cost	c;
	t_nod	*node;

	c.idx = idx;
	c.mov = 0;
	c.roro = 0;
	c.rrrr = 0;
	c.mova = 0;
	c.dira = 'f';
	node = a->top;
	while (node->idx != idx)
	{
		c.mova++;
		node = node->next;
	}
	c.rmva = pss_size(a) - c.mova;
	c.movb = 0;
	c.dirb = 'f';
	if ((b->sid < idx ) && (idx < b->bid))
	{
		node = b->top;
		while (!((node->prev->idx > idx) && (idx > node->idx)))
		{
			c.movb++;
			node = node->next;
		}
	}
	if ((idx < b->sid)|| (b->bid < idx))
	{
		node = b->top;
		while (node->idx != b->bid)
		{
			c.movb++;
			node = node->next;
		}
	}
	c.rmvb = pss_size(b) - c.movb;
	return (calculate(c));
}
/*
static t_cost	optimize(t_pss *a, t_pss *b, ssize_t idx)
{
	t_cost	c;

	c.idx = idx; 
	pss_extr(pss_deep(idx, a), a, &c.dira, &c.mova);
	pss_inse(idx, b, &c.dirb, &c.movb);
	ft_printf("idx = %d, movesa = %d dira = %c", idx, c.mova, c.dira);
	ft_printf(" movesb = %d dirb = %c",  c.movb, c.dirb);
	if ((c.dira == c.dirb) && (c.mova != 0) && (c.movb != 0))
	{q
		if (c.mova > c.movb)
			c.mov = c.mova;
		else
			c.mov = c.movb; 
	}
	else
		c.mov = c.mova + c.movb;
	ft_printf(" ==> moves = %d \n",  c.mov);
	return (c);
}

*/
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
		c = optimize2(a, b, node->idx);
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
