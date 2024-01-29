/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_ttop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:59:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_ttop.c
   @brief pss_ttop() rotates stack till idx is on top.

   @param[in] one: A stack to rotate.
   @param[in] idx: The index the stack must show on the top.

   @details
   Calculates required movements ra or rra to place idx on top.
   when moves not zero, execute de movements.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_ttop(t_pss *one, ssize_t idx)
{
	char	direction;
	short	moves;

	pss_extr(pss_deep(idx, one), one, &direction, &moves);
	if (moves != 0)
	{
		if (direction == 'f')
			pss_nrot(one, moves);
		else
			pss_nrro(one, moves);
	}
}
