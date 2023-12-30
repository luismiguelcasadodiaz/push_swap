/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_reve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:07 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 08:48:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

t_pss	*pss_reve(t_pss *s)
{
	t_pss	*a;
	t_nod	*nod;
	short	end;

	a = pss_init('a');
	if (!pss_empt(s))
	{
		end = 0;
		nod = s->top;
		while (!end)
		{
			end = (nod->next == s->top);
			pss_push(a, nod->num);
			nod = nod->next;
		}
	}
	pss_free(s);
	return (a);
}
