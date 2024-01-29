/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:59:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 22:23:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include <limits.h>

// case 1 : rota a & rota b

static t_cost	case1(t_cost c)
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
//	cos_show(c);
	return (c);
}

// case 2 : rota a & rrot b

static t_cost	case2(t_cost c)
{
	c.roro = 0;
	c.rrrr = 0;
	c.movb = 0;
	c.rmva = 0;
	c.mov = c.mova + c.rmvb;
//	cos_show(c);
	return (c);
}

// case 3 : rrot a & rota b

static t_cost	case3(t_cost c)
{
	c.roro = 0;
	c.rrrr = 0;
	c.rmvb = 0;
	c.mova = 0;
	c.mov = c.rmva + c.movb;
//	cos_show(c);
	return (c);
}

// case 4 : rrot a & rrot b

static t_cost	case4(t_cost c)
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
		c.rmvb = c.rmvb - c.rmva;
		c.rmva = 0;
	}
	c.mov = c.rrrr + c.rmva + c.rmvb;
	c.mova = 0;
	c.movb = 0;
//	cos_show(c);
	return (c);
}

t_cost	pss_calc(t_cost c)
{
	t_cost	option[4];
	short	i;
	short	imin;
	short	min;

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
