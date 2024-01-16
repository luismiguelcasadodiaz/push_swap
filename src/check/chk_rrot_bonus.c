/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:36:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:36:49 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		pss_rrot(a, NOPRINT);
	else if (move[2] == 'b')
		pss_rrot(b, NOPRINT);
	else if (move[2] == 'r')
		pss_rrrr(a, b, NOPRINT);
	else
		return (0);
	return (1);
}
