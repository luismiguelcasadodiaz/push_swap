/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:37:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

void	pss_free(t_pss *s)
{
	int		num;
	ssize_t	idx;

	while (s->top != NULL)
		pss_pope(s, &num, &idx);
	free(s);
}
//	short	end;
//	t_nod	*nod;
//	t_nod	*actual;
//
//	if (!pss_empt(s))
//	{
//		s->top->prev->next = NULL;
//		nod = s->top;
//		while (nod)
//		{
//			actual = nod;
//			nod = actual->next;
//			nod_free(nod);
//		}
//		nod = s->top->prev;
//		while (!end)
//		{
//			end = (nod->prev == s->top);
//			next = nod->prev;
//			nod_free(nod);
//			nod = next;
//		}
