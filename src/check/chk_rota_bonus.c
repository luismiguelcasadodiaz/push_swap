/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:39:14 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:39:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* ************************************************************************** */
/* chk_rota() calls the right pss rota function according to move's second    */
/*            char.                                                           */
/*                                                                            */
/* For ra calls pss_rota(a).                                                  */
/* For rb calls pss_rota(b).                                                  */
/* For rr calls pss_roro(a, b).                                               */
/*                                                                            */
/* Returns 1, informing the move was correct (sa, sb or ss), otherwise        */
/* returns 0.                                                                 */
/*                                                                            */
/* ************************************************************************** */
int	chk_rota(t_pss *a, t_pss *b, char *move)
{
	if (move[1] == 'a')
		pss_rota(a, NOPRINT);
	else if (move[1] == 'b')
		pss_rota(b, NOPRINT);
	else if (move[1] == 'r')
		pss_roro(a, b, NOPRINT);
	else
		return (0);
	return (1);
}
