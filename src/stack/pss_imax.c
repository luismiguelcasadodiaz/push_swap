/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_imax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 11:41:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_imax() search the biggest indexr stocked in the stack and returns it   */
/*                                                                            */
/* ************************************************************************** */
ssize_t	pss_imax(t_pss *s)
{
	t_nod	*nod;
	short	end;
	ssize_t	max;

	end = 0;
	nod = s->top;
	max = s->top->idx;
	while (!end)
	{
		end = (nod->next == s->top);
		nod = nod->next;
		if (max < nod->idx)
			max = nod->idx;
	}
	return (max);
}
