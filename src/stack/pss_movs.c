/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_movs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:22:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 15:19:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

void	pss_movs(t_pss *ori, t_pss *des)
{
	short	moves;
	char	direction;

	while (!pss_empt(ori))
	{
		moves = 0;
		if ((des->sid < ori->top->idx) && (ori->top->idx < des->bid))
			pss_extr(pss_nmtp(ori->top->idx, des), des, &direction, &moves);
		else if ((ori->top->idx < des->sid) || (des->bid < ori->top->idx))
			pss_extr(pss_deep(des->sid, des), des, &direction, &moves);
		if (moves != 0)
		{
			if (direction == 'f')
				pss_nrot(des, moves);
			else
				pss_nrro(des, moves);
		}
		pss_psoo(des, ori, PRINTME);
	}
}
