/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 17:46:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_mini() seacrh the smallest number stocked in the stack and returns it  */
/*                                                                            */
/* ************************************************************************** */
int	pss_mini(t_pss *s)
{
	t_nod	*nod;
	short	end;
	int		min;

	if (!pss_empt(s))
	{
		end = 0;
		nod = s->top;
		min = s->top->num;
		while (!end)
		{
			end = (nod->next == s->top);
			nod = nod->next;
			if (nod->num < min)
				min = nod->num;
		}
		return (min);
	}
	return (0);
}
