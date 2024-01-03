/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mami.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:49:40 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_mami_u() updates min and max according to the received num when push.  */
/*                                                                            */
/* GETS:                                                                      */
/* t_pss *s: stack                                                            */
/* int   num: Integer to check against current min and max                    */
/*                                                                            */
/* OPERATES:                                                                  */
/* Changes the interval's end corresponding to the side that num overpasses.  */
/*                                                                            */
/* If size == 1 both min & max match num.                                     */
/* ************************************************************************** */
static void	pss_mami_u(t_pss *s, int num)
{
	if (pss_size(s) == 1)
	{
		s->sma = num;
		s->big = num;
	}
	else
	{
		if (num < s->sma)
			s->sma = num;
		if (s->big < num)
			s->big = num;
	}
}

/* ************************************************************************** */
/* pss_mami_o() updates min and max according to the received num when pop.   */
/*                                                                            */
/* GETS:                                                                      */
/* t_pss *s: stack                                                            */
/* int   num: Integer to check against current min and max                    */
/*                                                                            */
/* OPERATES:                                                                  */
/*                                                                            */
/* If num belongs to the min..max interval, does nothing.                     */
/* But if num match one of the interveal min..max 's ends, then a new min or  */
/* max has to be found.                                                       */
/*                                                                            */
/* ************************************************************************** */
static void	pss_mami_o(t_pss *s, int num)
{
	if (pss_size(s) == 0)
	{
		s->sma = 0;
		s->big = 0;
	}
	else
	{
		if (s->sma == num)
			s->sma = pss_mini(s);
		if (s->big == num)
			s->big = pss_maxi(s);
	}
}

/* ************************************************************************** */
/* pss_mami() updates min and max according to the received num and the       */
/* operation performed.                                                       */
/*                                                                            */
/* GETS:                                                                      */
/* t_pss *s: stack                                                            */
/* int   num: Integer to check against current min and max                    */
/* char  c  : A char informing if 'u' push or 'o' pop operation               */
/*                                                                            */
/* OPERATES:                                                                  */
/* At push operations changes the interval's end corresponding to the side    */
/* that num overpasses.                                                       */
/*                                                                            */
/* At pop operations if num belongs to the min..max interval, does nothing.   */
/* But if num match one of the interveal min..max 's ends, then a new min or  */
/* max has to be found.                                                       */
/*                                                                            */
/* ************************************************************************** */
void	pss_mami(t_pss *s, int num, char c)
{
	if (c == 'u')
		pss_mami_u(s, num);
	else if (c == 'o')
		pss_mami_o(s, num);
}
