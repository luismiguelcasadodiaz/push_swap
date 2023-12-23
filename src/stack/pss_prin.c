/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:07 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/23 15:24:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

void	pss_prin(t_pss *s)
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
			end = (nod->next == NULL);
			ft_printf("%d ", nod->num);
		}
	}
	ft_printf(")\n");
}
