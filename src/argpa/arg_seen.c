/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_seen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:54:52 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/28 19:00:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "argpar.h"

/* ************************************************************************** */
/* arg_seen() check if num has been previously seen in the arguments.         */
/*                                                                            */
/* GETS:                                                                      */
/*  int  num: the num to see if exists inside the stack.                      */
/*  t_pss *a: the stack to save the arguments.                                */
/*                                                                            */
/* RETURNS:                                                                   */
/* Zero if the argument has not been seen previously. That is, it is not      */
/* inside the stack. One if the argument has been seen.                       */
/*                                                                            */
/* OPERATES:                                                                  */
/* Loops the stack looking for num. If there is not, pushes num into the stack*/
/* and returns zero. Otherwiser returns one ==> arg_seen == True              */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
int	arg_seen(int num, t_pss *a)
{
	if (!pss_have(a, num))
	{
		pss_push(a, num);
		return (0);
	}
	return (1);
}
