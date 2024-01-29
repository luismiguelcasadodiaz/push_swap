/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_inse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 19:33:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include "ft_printf.h"

/******************************************************************************/
/**
   @file pss_inse.c
   @brief pss_inse() calculates best direction and steps to insert a node in be

   @param[in]        idx: the idx to insert in an ordered position.
   @param[in]          b: a stack to insert the idx node in position.
   @param[out] direction: flag to rotate('f') or reverse rotate('b') is better
   @param[out]     moves: number of moves to insert the node in the stack.

   @details
   When the idx to insert is going to be a new smallest idx. No previous moves
   are required to position stactk b to receive idx. returns moves 0.

   When the idx to insert is going to be a new biggest idx, returns the number
   of rotations the stack b needs to situate actual biggest idx on stack's top.

   For other cases nmtp returns how deep idx has to go into de stack. 
   Returns a number of movements depending if the deepnest is above or below
   stack's half.
   
   if above half, deep regular rotations 'f'  will do the job.
   if below half, size - deep reversal rotations 'b' will do the job. 

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_inse(ssize_t idx, t_pss *b, char *direction, short *moves)
{
	ssize_t	size;
	ssize_t	half;
	ssize_t	deep;

	if ((idx < b->sid) || (b->bid < idx))
	{
		if (idx < b->sid)
			pss_extr(pss_deep(b->sid, b), b, direction, moves);
		if (b->bid < idx)
			pss_extr(pss_deep(b->bid, b), b, direction, moves);
		return ;
	}
	*direction = 'f';
	deep = pss_nmtp(idx, b);
	ft_printf("idx=%d - deep=%d, ", idx, deep);
	size = pss_size(b);
	half = size / 2;
	if (deep > half)
	{
		*direction = 'b';
		*moves = size - deep;
	}
	else
		*moves = deep;
}
