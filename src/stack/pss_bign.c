/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_bign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 19:17:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*./file pss_bign.c                                                          .*/
/*./brief pss_bign() returns the biggest number holded by the stack          .*/
/*.                                                                          .*/
/*./param[in]  s: The stack to return the biggest number from.               .*/
/*./                                                                         .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
int	pss_bign(t_pss *s)
{
	return (s->big);
}
