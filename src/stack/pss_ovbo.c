/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_ovbo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 18:08:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/**
   @file pss_ovbo.c
   @brief pss_ovbo() returns the over-botton-node of the stack's value.

   @param[in]  s: The stack to return the bottton value from.

   @author LMCD (Luis Miguel Casado Diaz)
 ****************************************************************************/
int	pss_ovbo(t_pss *s)
{
	return (s->top->prev->prev->num);
}
