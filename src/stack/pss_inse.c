/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_inse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/24 18:31:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_inse.c
   @brief pss_inse() calculates best direction and steps to extrac a node

   @param[in]       deep: the deep of the node we want to extract.
   @param[in]          s: Non-empty stack to extract the node from.
   @param[out] direction: flag to rotate('f') or reverse rotate('b') is better
   @param[out]     moves: numpre of moves to extract the node

   @details
   Calculates stack's half. If node is deeper than half it is more convenient
   reverse rotate ('b'), If node is before stack's half it is more convenient
   rotate ('f').

   Calculates the number of moves.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_inse(ssize_t idx, t_pss *a, char *direction, short *moves)
{
	ssize_t	size;
	ssize_t	half;
	ssize_t deep;

	if ((idx < a->sid) || (a->bid < idx))
	{
		*moves = 0;
		*direction = 'f';
		return ;
	}
	deep = pss_nmtp(idx, a);
	size = pss_size(a);
	half = size / 2;
	if (deep > half)
	{
		*direction = 'b';
		*moves = size - deep + 1;
	}
	else
	{
		*direction = 'f';
		*moves = deep;
	}
}
