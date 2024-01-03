/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_unpe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/02 23:36:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*./file pss_bott.c                                                          .*/
/*./brief pss_bott() returns the value holded by the botton node of the stack.*/
/*.                                                                          .*/
/*./param[in]  s: The stack to return the bottton value from.                .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
int	pss_unpe(t_pss *s)
{
	return (s->top->next->num);
}
