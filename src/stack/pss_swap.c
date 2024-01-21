/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 15:55:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/******************************************************************************/
/**
   @file pss_swap.c
   @brief pss_swap()swaps the values between top node and the top node's next.

   @param[in]  s: Non-empty stack
   @param[in] printme: it is a flag to print a message or act silently.

   @details
   Swaps node data between top node and undertop nodes.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_swap(t_pss *s, int printme)
{
	int		num;
	ssize_t	idx;

	if (pss_empt(s))
		return ;
	num = s->top->num;
	idx = s->top->idx;
	s->top->num = s->top->next->num;
	s->top->idx = s->top->next->idx;
	s->top->next->num = num;
	s->top->next->idx = idx;
	if (printme)
		ft_printf("s%c\n", s->nam);
}
