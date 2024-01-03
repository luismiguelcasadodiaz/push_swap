/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_swsw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:50:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_swsw() swaps the two top nodes of the two stacks passed as params      */
/*                                                                            */
/* ************************************************************************** */
void	pss_swsw(t_pss *a, t_pss *b, int printme)
{
	pss_swap(a, NOPRINT);
	pss_swap(b, NOPRINT);
	if (printme)
		ft_printf("ss\n");
}
