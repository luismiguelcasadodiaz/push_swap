/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_trea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:40:23 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:52:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* ************************************************************************** */
/* chk_trea() analyses the argument. If it is a move, executes the move.      */
/*                                                                            */
/* To see numbers changing between stacks insert                              */
/*           pss_prnu(a);                                                     */
/*           pss_prnu(b);                                                     */
/* before the return  statement.                                              */
/*                                                                            */
/* to see stack shape simulated with asterisks insert                         */
/*           chk_prin(a, b);                                                  */
/* before the return statement                                                */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
int	chk_trea(char *arg, t_pss *a, t_pss *b)
{
	int	result;

	result = 0;
	if (arg[0] == 's')
		result = chk_swap(a, b, arg);
	else if (arg[0] == 'p')
		result = chk_psoo(a, b, arg);
	else if (arg[0] == 'r')
	{
		if (ft_strlen(arg) == 3)
			result = chk_rota(a, b, arg);
		else
			result = chk_rrot(a, b, arg);
	}
	else
		result = 0;
	return (result);
}
