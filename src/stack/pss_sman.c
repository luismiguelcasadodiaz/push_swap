/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_sman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 19:14:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*./file pss_sman.c                                                          .*/
/*./brief pss_sman() returns the smallest number holded by the stack         .*/
/*.                                                                          .*/
/*./param[in]  s: The stack to return the smallest number from.              .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Díaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
int	pss_sman(t_pss *s)
{
	return (s->sma);
}
