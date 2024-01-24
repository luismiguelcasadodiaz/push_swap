/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_imin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 11:40:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_imin() seacrh the smallest index  stocked in the stack and returns it  */
/*                                                                            */
/* ************************************************************************** */
ssize_t	pss_imin(t_pss *s)
{
	t_nod	*nod;
	short	end;
	ssize_t	min;

	if (!pss_empt(s))
	{
		end = 0;
		nod = s->top;
		min = s->top->idx;
		while (!end)
		{
			end = (nod->next == s->top);
			nod = nod->next;
			if (nod->idx < min)
				min = nod->idx;
		}
		return (min);
	}
	return (0);
}
