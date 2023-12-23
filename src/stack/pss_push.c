/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/23 15:30:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

int	pss_push(t_pss *s, int num)
{
	t_nod	*n;

	n = nod_init(num);
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
		n->prev = s->top->prev;
		n->next = s->top->next;
		s->top = n;
	}
	return (0);
}
