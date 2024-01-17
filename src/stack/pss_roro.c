/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_roro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/17 10:00:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* pss_roro() rotates simultaneously both stacks got as parameters.           */
/*                                                                            */
/* Rotates the stacks in such a way that the first node becomes last          */
/*                                                                            */
/* ************************************************************************** */
void	pss_roro(t_pss *a, t_pss *b, int printme)
{
	pss_rota(a, NOPRINT);
	pss_rota(b, NOPRINT);
	if (printme)
		ft_printf("rr\n");
}
