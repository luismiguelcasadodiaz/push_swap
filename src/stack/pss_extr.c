/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_extr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/24 17:41:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_extr.c
   @brief pss_extr() calculates best direction and steps to extrac a node

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
void	pss_extr(ssize_t deep, t_pss *a, char *direction, short *moves)
{
	ssize_t	size;
	ssize_t	half;

	*direction = 'f';
	*moves = 0;
	if (deep == 0)
		return ;
	size = pss_size(a);
	half = size / 2;
	if (deep > half)
	{
		*direction = 'b';
		*moves = size - deep + 1;
	}
	else
		*moves = deep - 1;
}
