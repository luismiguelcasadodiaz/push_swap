/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_isor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:33:47 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 12:33:08 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* pss_isor() checks if the elemnts in the stack are stored ordered, either   */
/* in ascendand or descendand.                                                */
/*                                                                            */
/* An ascendat ordered arguments shall raise an error.                        */
/*                                                                            */
/* A command line 1 2 3 4 5, is stored in the stack as 5 4 3 2 1.             */ 
/* THis funciton raise the hand when it detects a descendat ordered stack     */
/*                                                                            */
/* GETS:                                                                      */
/* t_pss *s: the stack for verification.                                      */
/*                                                                            */
/* RETURNS:                                                                   */
/* ZERO when the stack is not ordered. otherwise returns ONE.                 */
/* An empty stack or a stack with one        elements returns 0 (not ordered) */
/*                                                                            */
/*                                                                            */
/* OPERATES:                                                                  */
/* Loops the stack tracking if actual is smaller than next (ascend) and       */
/* tracking if actual is bigger than next (descen).                           */
/*                                                                            */
/* Loops ends either exhausting the stack or when nor ascendant or descendand */
/* order is possible.                                                         */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

int	pss_isor(t_pss	*s)
{
	t_nod	*nod;
	int	num;
	int	end;
//	int	ascend;
	int	descen;

	if (pss_empt(s) || (pss_size(s) <= 2))
		return (0);
//	ascend = 1;
	descen = 1;
	nod = s->top;
	end = 0;
	num = nod->num;
//	while (!end && (ascend || descen))
	while (!end && descen)
	{
		end = (nod->next == s->top);
		if (!end)
		{
			//ascend = ascend && (num < nod->next->num);
			descen = descen && (nod->next->num < num);
		}
		nod = nod->next;
		num = nod->num;
	}
	//return ((ascend || descen));
	return (descen);
}
