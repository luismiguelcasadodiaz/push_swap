/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_psoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:12:19 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 16:52:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* ************************************************************************** */
/* chk_psoo() calls the right pss push function according to move's second    */
/*            char.                                                           */
/*                                                                            */
/* For pa calls pss_psoo(a, b).                                               */
/* For pb calls pss_psoo(b, a).                                               */
/*                                                                            */
/* Returns 1, informing the move was correct (sa, sb or ss), otherwise        */
/* returns 0.                                                                 */
/*                                                                            */
/* ************************************************************************** */
int	chk_psoo(t_pss *a, t_pss *b, char *move)
{
	if (move[1] == 'a')
		pss_psoo(a, b, PRINTME);
	else if (move[1] == 'b')
		pss_psoo(b, a, PRINTME);
	else
		return (0);
	return (1);
}
