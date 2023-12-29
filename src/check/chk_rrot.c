/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:12:19 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 17:08:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* ************************************************************************** */
/* chk_rrot() calls the right pss rrot function according to move's third     */
/*            char.                                                           */
/*                                                                            */
/* For rra calls pss_rrot(a).                                                 */
/* For rrb calls pss_rrot(b).                                                 */
/* For rrr calls pss_rrrr(a, b).                                              */
/*                                                                            */
/* Returns 1, informing the move was correct (sa, sb or ss), otherwise        */
/* returns 0.                                                                 */
/*                                                                            */
/* ************************************************************************** */
int	chk_rrot(t_pss *a, t_pss *b, char *move)
{
	if (move[2] == 'a')
		pss_rrot(a, PRINTME);
	else if (move[2] == 'b')
		pss_rrot(b, PRINTME);
	else if (move[2] == 'r')
		pss_rrrr(a, b, PRINTME);
	else
		return (0);
	return (1);
}
