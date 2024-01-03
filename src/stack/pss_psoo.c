/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_psoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:47:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_psoo() push into one destination stack the other's top (origin) node.  */
/*            do it if origin is not empty                                    */
/* ************************************************************************** */
void	pss_psoo(t_pss *dst, t_pss *ori, int printme)
{
	int	num;

	if (!pss_empt(ori))
	{
		pss_pope(ori, &num);
		pss_push(dst, num);
	}
	if (printme)
		ft_printf("p%c\n", dst->nam);
}
