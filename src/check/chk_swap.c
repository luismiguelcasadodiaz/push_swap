/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:12:19 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 16:36:03 by luicasad         ###   ########.fr       */
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
		pss_swap(a, PRINTME);
	else if (move[1] == 'b')
		pss_swap(b, PRINTME);
	else if (move[1] == 's')
		pss_swsw(a, b, PRINTME);
	else
		return (0);
	return (1);
}
