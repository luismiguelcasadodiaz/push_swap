/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_have.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 17:57:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/******************************************************************************/
/**
   @file pss_have.c
   @brief pss_have() returns 1 when the num is found in the stack, 0 otherwise.

   @param[in] t_pss *s:the stack to find the number in.
   @param[in] int  num:the num to look for.

   @details
   Set the hypothesis that does not have the num (have = 0)
   Loops the stack till the end, quitting when node->num matchs num and
   setting the have to 1, to return a (ss_have == True)

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	pss_have(t_pss *s, int num)
{
	int		have;
	short	end;
	t_nod	*nod;

	have = 0;
	if (!pss_empt(s))
	{
		end = 0;
		nod = s->top;
		while (!end && !have)
		{
			end = (nod->next == s->top);
			have = (nod->num == num);
			nod = nod->next;
		}
	}
	return (have);
}
