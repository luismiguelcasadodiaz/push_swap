/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_psoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/17 09:59:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* pss_psoo() push into one destination stack the other's top (origin) node.  */
/*            do it if origin is not empty                                    */
/* ************************************************************************** */
void	pss_psoo(t_pss *dst, t_pss *ori, int printme)
{
	int		num;
	ssize_t	idx;

	if (!pss_empt(ori))
	{
		pss_pope(ori, &num, &idx);
		pss_push(dst, num, idx);
	}
	if (printme)
		ft_printf("p%c\n", dst->nam);
}
