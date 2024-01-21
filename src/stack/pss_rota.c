/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_rota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 15:54:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* pss_rota() moves top to the top's next node, making the first the last.    */
/*                                                                            */
/* ************************************************************************** */
void	pss_rota(t_pss *s, int printme)
{
	if (pss_empt(s))
		return ;
	s->top = s->top->next;
	if (printme)
		ft_printf("r%c\n", s->nam);
}
