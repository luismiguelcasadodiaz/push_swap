/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_peek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 10:58:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/******************************************************************************/
/**
   @file pss_peek.c
   @brief pss_peek() returns the value holded by the top node of the stack
                                                                                
   @param[in]  s: The stack to return the top value from.                        
                                                                                
   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	pss_peek(t_pss *s)
{
	return (s->top->num);
}
