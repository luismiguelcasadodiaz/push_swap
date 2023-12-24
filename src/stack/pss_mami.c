/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mami.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/24 15:43:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

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
	{
		if (num < s->sma)
			s->sma = num;
		if (s->big < num)
			s->big = num;
	}
	else if (c == 'o')
	{
		if (s->sma == num)
			s->sma = pss_mini(s);
		if (s->big == num)
			s->big = pss_maxi(s);
	}
}
