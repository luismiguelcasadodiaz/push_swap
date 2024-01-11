/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:08:13 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 18:50:11 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ps_sor5_aux(t_pss *a, t_pss *b)
{
	int	num_rota;

	num_rota = 0;
	while (pss_peek(a) < pss_bign(b))
	{
		if (pss_peek(b) == pss_bign(b))
			pss_rota(a, PRINTME);
		else
			pss_roro(a, b, PRINTME);
		num_rota++;
	}
	while (!pss_empt(b))
	{
		if (pss_unpe(b) < pss_bott(a))
		{
			pss_psoo(a, b, PRINTME);
			pss_rrot(a, PRINTME);
			num_rota--;
		}
		else
			pss_psoo(a, b, PRINTME);
	}
	while (num_rota)
	{
		pss_rrot(a, PRINTME);
		num_rota--;
	}
}

/* ************************************************************************** */
/* ps_sor5() sort a 5-element stack                                           */
/*                                                                            */
/* 1.- Pass 2 elements to stack b                                             */
/* 2.- Sort 3 elements of stack a                                             */
/*                                                                            */
/* Let's see scenarios                                                        */
/*  '[' stands for min of stack                                               */
/*  ']' stands for max of stack                                               */
/*                                                                            */
/*      |no overlapp |      there is overlapp     |            |              */
/* Case |      1     |    2    |   3    |    4    |     5      |              */
/* -----|------------|---------|--------|---------|------------|              */
/*   a  |     [    ] |  [    ] | [    ] | [    ]  | [    ]     |              */
/*   b  | [  ]       | [  ]    |  [  ]  |    [  ] |       [  ] |              */
/*                                                                            */
/* When case is not 3 add one after other                                     */
/*                                                                            */
/* 3.- From stack b add the 4th element to stack a                            */
/* 4.- From stack b add the 5th element to stack a                            */
/*                                                                            */
/* When case is 3, it is too expensive dig twice into middle of stack.        */
/*                                                                            */
/* Case 3 ==> (pss_sman(a) < pss_sman(b)) && (pss_bign(b) < pss_bign(a))      */
/*                                                                            */
/* ************************************************************************** */
void	ps_sor5(t_pss *a, t_pss *b)
{
	pss_psoo(b, a, PRINTME);
	pss_psoo(b, a, PRINTME);
	ps_sor3(a);
	if ((pss_sman(a) < pss_sman(b)) && (pss_bign(b) < pss_bign(a)))
		ps_sor5_aux(a, b);
	else
	{
		ps_add4(a, b);
		ps_add5(a, b);
	}
}
