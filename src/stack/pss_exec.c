/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:19:22 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/30 09:28:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

/******************************************************************************/
/**
   @file pss_exec.c
   @brief ps_exec() sorts stack a with Turkish algoritm.

   @param[in]  c: A t_cost struct with number of movements of each type.

   @details
   Checks all structs's fields bigger than zero and executes corresponding
   movement

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_exec(t_pss *a, t_pss *b, t_cost c)
{
	if (c.roro)
		pss_nror(a, b, c.roro);
	if (c.rrrr)
		pss_nrrr(a, b, c.rrrr);
	if (c.mova)
		pss_nrot(a, c.mova);
	if (c.rmva)
		pss_nrro(a, c.rmva);
	if (c.movb)
		pss_nrot(b, c.movb);
	if (c.rmvb)
		pss_nrro(b, c.rmvb);
}
