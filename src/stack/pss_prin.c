/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 17:09:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/******************************************************************************/
/**
   @file pss_prin.c
   @brief pss_prin() prints indexes of stack's nodes                      
                                                                                
   @param[in]  s: The stack to Rprint the values from.                        
                                                                                
   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_prin(t_pss *s)
{
	t_nod	*nod;
	short	end;

	ft_printf("pss(%c){I:%d, [%d..%d]}(", s->nam, s->siz, s->sma, s->big);
	if (pss_empt(s))
		ft_printf("empty");
	else
	{
		end = 0;
		nod = s->top;
		while (!end)
		{
			end = (nod->next == s->top);
			ft_printf("%d ", nod->idx);
			nod = nod->next;
		}
	}
	ft_printf(")\n");
}
