/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 16:00:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* pss_rrot() moves top to the top's next node, making the last  the first.   */
/*                                                                            */
/* ************************************************************************** */
void	pss_rrot(t_pss *s, int printme)
{
	if (pss_empt(s))
		return ;
	s->top = s->top->prev;
	if (printme)
		ft_printf("rr%c\n", s->nam);
}
