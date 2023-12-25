/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/25 10:47:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_swap() swaps the values between top node and the top node's next.      */
/*                                                                            */
/* ************************************************************************** */
void	pss_swap(t_pss *s, int printme)
{
	int	num;

	num = s->top->num;
	s->top->num = s->top->next->num;
	s->top->next->num = num;
	if (printme)
		ft_printf("s%c\n", s->nam);
}
