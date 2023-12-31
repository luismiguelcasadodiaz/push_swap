/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_pall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:02:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 09:35:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

/* ************************************************************************** */
/* pss_pall() pushes all nodes from origin to destination                     */
/*                                                                            */
/* ************************************************************************** */
void	pss_pall(t_pss *dst, t_pss *ori)
{
	while (!pss_empt(ori))
	{
		pss_psoo(dst, ori, PRINTME);
	}
}
