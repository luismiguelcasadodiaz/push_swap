/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_bott.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 18:05:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/******************************************************************************/
/**
   @file pss_bott.c
   @brief pss_bott() returns stack's bottom-node's value.

   @param[in]  s: The stack to return the bottom value from.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	pss_bott(t_pss *s)
{
	return (s->top->prev->num);
}
