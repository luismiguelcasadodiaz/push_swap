/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:57:44 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 14:00:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* ps_add5() insert into a 4-number ordered stack a fifth element             */
/*                                                                            */
/* The function deals with 4 cases:                                           */
/*                                                                            */
/* >----< Case 1 pss_peek(b) < pss_peak(a)               pa                   */
/*   a1                                                                       */
/* >----< Case 2 pss_peek(b) < pss_unpe(a)               ra pa rra            */
/*   a2                                                                       */
/* >----< Case 3 pss_unpe(a) < pss_peek(b) < pss_ovbo(a) ra ra pa rra rra rra */
/*   a3                                                                       */
/* >----< Case 4 pss_ovbo(a) < pss_peek(b) < pss_bott(a) rra pa ra ra         */
/*   a4                                                                       */
/* >----< Case 5 pss_bott(a) < pss_peek(b)               pa ra                */
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
		pss_nrot(a, 3);
	}
	else
		add_fourth(a, b);
}
