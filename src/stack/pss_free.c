/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 08:20:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

void	pss_free(t_pss *s)
{
	int	num;

	while (s->top != NULL)
		pss_pope(s, &num);
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
