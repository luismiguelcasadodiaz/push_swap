/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_maxi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:48:43 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

int	pss_maxi(t_pss *s)
{
	t_nod	*nod;
	short	end;
	int		max;

	end = 0;
	nod = s->top;
	max = s->top->num;
	while (!end)
	{
		end = (nod->next == s->top);
		nod = nod->next;
		if (max < nod->num)
			max = nod->num;
	}
	return (max);
}
