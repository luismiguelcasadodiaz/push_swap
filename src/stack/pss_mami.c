/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mami.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/22 11:33:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/**
   @file pss_mami.c
   @brief pss_mami_u() updates min/max according the last pushed num & idx.

   @param[in] t_pss    *s: stack
   @param[in] int	  num: Integer to check against current sma and big
   @param[in] ssize_t idx: Index   to check against current sid and bid

   @details:
   Changes the interval's end corresponding to the side that num overpasses.
   If size == 1 both sma & big match num.
   Changes the interval's end corresponding to the side that idx overpasses.
   If size == 1 both sid & bid match num.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static void	pss_mami_u(t_pss *s, int num, ssize_t idx)
{
	if (pss_size(s) == 1)
	{
		s->sma = num;
		s->big = num;
		s->bid = idx;
		s->sid = idx;
	}
	else
	{
		if (num < s->sma)
			s->sma = num;
		if (s->big < num)
			s->big = num;
		if (idx < s->sid)
			s->sid = idx;
		if (s->bid < idx)
			s->bid = idx;
	}
}

/* ************************************************************************** */
/**
	@file pss_mami.c
	@brief  pss_mami_o() updates min/max according to last poped num & idx

	@param[in] t_pss    *s: stack.
	@param[in] int	   num: integer to check against current sma and big.
	@param[in] ssize_t idx: Index   to check against current sid and bid.

	@details
   If num/idx belongs to the sma/sid..big/bid interval, does nothing.
   But if num/idx match one of the interveal sma/sid..big/bid 's ends,
   then a new min or max has to be found.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static void	pss_mami_o(t_pss *s, int num, ssize_t idx)
{
	if (pss_size(s) == 0)
	{
		s->sma = 0;
		s->big = 0;
		s->big = 0;
		s->sid = 0;
	}
	else
	{
		if (s->sma == num)
			s->sma = pss_mini(s);
		if (s->big == num)
			s->big = pss_maxi(s);
		if (s->sid == idx)
			s->sid = pss_imin(s);
		if (s->big == idx)
			s->bid = pss_imax(s);
	}
}

/* ************************************************************************** */
/**
   pss_mami() updates min and max according to the received num and the
   operation performed.

   @paramìn+ t_pss     *s: stack
   @param[in] int     num: Integer to check against current min and max
   @param[in] ssize_t idx: Index to check against current sid and bid
   @param[in] char      c  : A char informing if 'u' push or 'o' pop operation

   @details
   At push operations changes the interval's end corresponding to the side
   that num overpasses.

   At pop operations if num belongs to the min..max interval, does nothing.
   But if num match one of the interveal min..max 's ends, then a new min or
   max has to be found.


   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	pss_mami(t_pss *s, int num, ssize_t idx, char c)
{
	if (c == 'u')
		pss_mami_u(s, num, idx);
	else if (c == 'o')
		pss_mami_o(s, num, idx);
}
