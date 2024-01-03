/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:08:13 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/03 01:34:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* add_fifth() insert into a 4-number ordered stack a fifth element           */
/*                                                                            */
/* The function deals with 4 cases:                                           */
/*                                                                            */
/*     >----< Case 1 pss_peek(b) < pss_peak(a)               pa               */
/*       a1                                                                   */
/*     >----< Case 2 pss_peek(b) < pss_unpe(a)               ra pa rra        */
/*       a2                                                                   */
/*     >----< Case 3 pss_unpe(a) < pss_peek(b) < pss_ovbo(a) ra ra pa rra rra */
/*       a3                                                                   */
/*     >----< Case 4 pss_ovbo(a) < pss_peek(b) < pss_bott(a) rra pa ra ra     */
/*       a4                                                                   */
/*     >----< Case 5 pss_bott(a) < pss_peek(b)               pa ra            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/* add_fourth() insert into a 3-number ordered stack a fourth element         */
/*                                                                            */
/* The function deals with 4 cases:                                           */
/*                                                                            */
/*     >----< Case 1 pss_peek(b) < pss_peak(a)               pa               */
/*       a1                                                                   */
/*     >----< Case 2 pss_peek(b) < pss_unpe(a)               ra pa rra        */
/*       a2                                                                   */
/*     >----< Case 3 pss_unpe(a) < pss_peek(b) < pss_bott(a) rra pa ra ra     */
/*       a3                                                                   */
/*     >----< Case 4 pss_bott(a) < pss_peek(b)               pa ra            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	add_fourth(t_pss *a, t_pss *b)
{
	if (pss_peek(b) < pss_peek(a))
		pss_psoo(a, b, PRINTME);
	else if (pss_peek(b) < pss_unpe(a))
	{
		pss_rota(a, PRINTME);
		pss_psoo(a, b, PRINTME);
		pss_rrot(a, PRINTME);
	}
	else if ((pss_unpe(a) < pss_peek(b)) && (pss_peek(b) < pss_bot(a)))
	{
		pss_rrot(a, PRINTME);
		pss_psoo(a, b, PRINTME);
		pss_rota(a, PRINTME);
		pss_rota(a, PRINTME);
	}
	else if (pss_bott(a) < pss_peek(b))
	{
		pss_psoo(a, b, PRINTME);
		pss_rota(a, PRINTME);
	}
}


void	ps_sor5(t_pss *a, t_pss *b)
{
	pss_psoo(b, a, PRINTME);
	pss_psoo(b, a, PRINTME);
	ps_sor3(a);
	pss_prin(a);
	add_fourth(a, b);
	pss_prin(a);
	add_fourth(a, b);
}
