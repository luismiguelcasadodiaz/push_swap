/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:57:44 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/05 15:32:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* ps_add6() insert into a 5-number ordered stack a sixth element             */
/*                                                                            */
/* The function deals with 5 cases:                                           */
/*                                                                            */
/* >--< Case 1 pss_peek(b) < pss_peak(a)               pa                   1 */
/*   a1                                                                       */
/* >--< Case 2 pss_peek(b) < pss_unpe(a)               ra pa rra            3 */
/*   a2                                                                       */
/* >--< Case 3 pss_unpe(a) < pss_peek(b) < pss_ovbo(a) rra rra pa rra rra   5 */
/*   a3                                                                       */
/* >--< Case 4 pss_ovbo(a) < pss_peek(b) < pss_bott(a) rra pa ra ra         4 */
/*   a4                                                                       */
/* >--< Case 4 pss_ovbo(a) < pss_peek(b) < pss_bott(a) rra pa ra ra         4 */
/*   a5                                                                       */
/* >--< Case 6 pss_bott(a) < pss_peek(b)               pa ra                2 */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
void	ps_add5(t_pss *a, t_pss *b)
{
	if ((pss_unpe(a) < pss_peek(b)) && (pss_peek(b) < pss_ovbo(a)))
	{
		pss_nrro(a, 2);
		pss_psoo(a, b, PRINTME);
		pss_nrro(a, 2);
	}
	else
		ps_add4(a, b);
}
