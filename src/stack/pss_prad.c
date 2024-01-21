/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:01:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 11:31:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include "libft.h"

/******************************************************************************/
/**
   @file pss_prad.c
   @brief pss_prad() implements one iteration of Radix Sort algorithm

   @param[in]   a: Stack to analize indexes.
   @param[in]   b: Stack for moving a nodes having zero in bit pos. 
   @param[in] pos: the position fo te bit we want to analise.

   @details
   Loops the stack. For each node analyzes stack top index's bit pos. rotates
   when bit pos is 1, and move to b stack when bit pos is 0.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_prad(t_pss *a, t_pss *b, ssize_t pos)
{
	ssize_t	loops;

	loops = pss_size(a);
	while (loops)
	{
		if (ft_bit(pos, pss_peek_idx(a)))
			pss_rota(a, PRINTME);
		else
			pss_psoo(b, a, PRINTME);
		loops--;
	}
}
