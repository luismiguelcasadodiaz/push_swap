/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prnu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:08:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

void	pss_prnu(t_pss *s)
{
	t_nod	*nod;
	short	end;

	ft_printf("pss(%c){#:%d, [%d..%d]}(", s->nam, s->siz, s->sma, s->big);
	if (pss_empt(s))
		ft_printf("empty");
	else
	{
		end = 0;
		nod = s->top;
		while (!end)
		{
			end = (nod->next == s->top);
			ft_printf("%d ", nod->num);
			nod = nod->next;
		}
	}
	ft_printf(")\n");
}
