/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_psoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:37:05 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:37:09 by luicasad         ###   ########.fr       */
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
		pss_psoo(a, b, NOPRINT);
	else if (move[1] == 'b')
		pss_psoo(b, a, NOPRINT);
	else
		return (0);
	return (1);
}
