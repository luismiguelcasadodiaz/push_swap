/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_maxi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 17:47:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_maxi() search the biggest number stocked in the stack and returns it   */
/*                                                                            */
/* ************************************************************************** */
int	pss_maxi(t_pss *s)
{
	t_nod	*nod;
	short	end;
	int		max;

	end = 0;
	nod = s->top;
	max = s->top->num;
	while (!end)
	{
		end = (nod->next == s->top);
		nod = nod->next;
		if (max < nod->num)
			max = nod->num;
	}
	return (max);
}
