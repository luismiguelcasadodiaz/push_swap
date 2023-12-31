/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:36:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

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
	pss_mami(s, num, 'u');
	return (0);
}
