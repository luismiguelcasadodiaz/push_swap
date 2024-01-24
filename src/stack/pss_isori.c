/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_isori.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:52:53 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 14:33:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/* ************************************************************************** */
/**
   @file pss_isori.c
   @brief pss_isori() checks if stack's values are stored in ascendan order.

   @param[in] t_pss *s: the stack for verification.

   @retunrs
   ZERO when the stack is not ordered. otherwise returns ONE.
   An empty stack or a stack with one element returns 0 (not ordered)


   @details
   An ascendat ordered arguments shall raise an error.

   This function raise the hand when it detects an ascendanid ordered stack

   Loops the stack tracking if actual is smaller than next (ascend)

   Loops ends either exhausting the stack or when ascendant is impossible.

 ****************************************************************************/

int	pss_isori(t_pss	*s)
{
	t_nod	*nod;
	int		idx;
	int		end;
	int		descend;

	if (pss_empt(s) || (pss_size(s) < 2))
		return (0);
	descend = 1;
	nod = s->top;
	end = 0;
	idx = nod->idx;
	while (!end && descend)
	{
		end = (nod->next == s->top);
		if (!end)
		{
			descend = descend && (idx > nod->next->idx);
		}
		nod = nod->next;
		idx = nod->idx;
	}
	return (descend);
}
