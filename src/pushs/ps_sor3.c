/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:59:33 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 11:56:08 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_sor3(t_pss *a)
{

	if (pss_peek(a) == a->big)
	{
		pss_rota(a, PRINTME);
		if (pss_peek(a) != a->sma)
			pss_swap(a, PRINTME);
	}
	else if (pss_peek(a) == a->sma)
	{
		pss_rota(a, PRINTME);
		if (pss_peek(a) == a->big)
		{
			pss_swap(a, PRINTME);
			pss_rrot(a, PRINTME);
		}
	}
	else
	{
		pss_swap(a, PRINTME);
		ps_sor3(a);
	}
}

