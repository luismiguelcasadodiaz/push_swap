/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:36:18 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:36:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* ************************************************************************** */
/* chk_swap() calls the right pss swap function according to move's second    */
/*            char.                                                           */
/*                                                                            */
/* For sa calls pss_swap(a).                                                  */
/* For sb calls pss_swap(b).                                                  */
/* For ss calls pss_swsw(a, b).                                               */
/*                                                                            */
/* Returns 1, informing the move was correct (sa, sb or ss), otherwise        */
/* returns 0.                                                                 */
/*                                                                            */
/* ************************************************************************** */
int	chk_swap(t_pss *a, t_pss *b, char *move)
{
	if (move[1] == 'a')
		pss_swap(a, NOPRINT);
	else if (move[1] == 'b')
		pss_swap(b, NOPRINT);
	else if (move[1] == 's')
		pss_swsw(a, b, NOPRINT);
	else
		return (0);
	return (1);
}
