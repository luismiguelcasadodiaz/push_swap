/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_rrrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/17 10:01:31 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* pss_rrrr() rotates simultaneously both stacks got as parameters.           */
/*                                                                            */
/* Rotates the stacks in such a way that the last  node becomes first         */
/*                                                                            */
/* ************************************************************************** */
void	pss_rrrr(t_pss *a, t_pss *b, int printme)
{
	pss_rrot(a, NOPRINT);
	pss_rrot(b, NOPRINT);
	if (printme)
		ft_printf("rrr\n");
}
