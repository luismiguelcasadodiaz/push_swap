/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_isor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:52:53 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 14:26:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/* ************************************************************************** */
/**
   @file pss_isor.c
   @brief pss_isor() checks if stack's values are stored in ascendan order.

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

int	pss_isor(t_pss	*s)
{
	t_nod	*nod;
	int		num;
	int		end;
	int		ascend;

	if (pss_empt(s) || (pss_size(s) < 2))
		return (0);
	ascend = 1;
	nod = s->top;
	end = 0;
	num = nod->num;
	while (!end && ascend)
	{
		end = (nod->next == s->top);
		if (!end)
		{
			ascend = ascend && (num < nod->next->num);
		}
		nod = nod->next;
		num = nod->num;
	}
	return (ascend);
}
