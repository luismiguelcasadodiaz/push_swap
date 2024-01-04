/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:52:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 13:57:34 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* ps_add4() insert into a 3-number ordered stack a fourth element            */
/*                                                                            */
/* The function deals with 4 cases:                                           */
/*                                                                            */
/* >----< Case 1 pss_peek(b) < pss_peak(a)               pa                   */
/*   a1                                                                       */
/* >----< Case 2 pss_peek(b) < pss_unpe(a)               ra pa rra            */
/*   a2                                                                       */
/* >----< Case 3 pss_unpe(a) < pss_peek(b) < pss_bott(a) rra pa ra ra         */
/*   a3                                                                       */
/* >----< Case 4 pss_bott(a) < pss_peek(b)               pa ra                */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
void	ps_add4(t_pss *a, t_pss *b)
{
	if (pss_peek(b) < pss_peek(a))
		pss_psoo(a, b, PRINTME);
	else if (pss_peek(b) < pss_unpe(a))
	{
		pss_rota(a, PRINTME);
		pss_psoo(a, b, PRINTME);
		pss_rrot(a, PRINTME);
	}
	else if ((pss_unpe(a) < pss_peek(b)) && (pss_peek(b) < pss_bott(a)))
	{
		pss_rrot(a, PRINTME);
		pss_psoo(a, b, PRINTME);
		pss_nrot(a, 2);
	}
	else if (pss_bott(a) < pss_peek(b))
	{
		pss_psoo(a, b, PRINTME);
		pss_rota(a, PRINTME);
	}
}
