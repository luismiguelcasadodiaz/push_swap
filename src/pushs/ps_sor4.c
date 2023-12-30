/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:59:33 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 11:58:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ps_prr(t_pss *a, t_pss *b)
{
	pss_psoo(a, b, PRINTME);
	pss_rrot(a, PRINTME);
}

static void	ps_rprr(t_pss *a, t_pss *b)
{
	pss_rota(a, PRINTME);
	pss_psoo(a, b, PRINTME);
	pss_rrot(a, PRINTME);
}

static void	ps_rrpr(t_pss *a, t_pss *b)
{
	pss_rrot(a, PRINTME);
	pss_psoo(a, b, PRINTME);
	pss_rota(a, PRINTME);
}

void	ps_sor4(t_pss *a, t_pss *b)
{
	int	min;
	int	max;

	min = a->sma;
	max = a->big;
	pss_psoo(b, a, PRINTME);
	ps_sor3(a);
	if (pss_peek(b) == max)
		ps_prr(a,b);
	else if (pss_peek(b) == min)
		pss_psoo(a, b, PRINTME);
	else if (pss_peek(b) < a->top->next->num)
		ps_rprr(a, b);
	else
		ps_rrpr(a, b);
}


