/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_trea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:00:44 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 09:16:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* ************************************************************************** */
/* chk_trea() analyses the argument. if it is a num, push it. it it is a move */
/*            Rexecutes the move.                                             */
/* ************************************************************************** */
int	chk_trea(char *arg, t_pss *a, t_pss *b)
{
	int	result;

	ft_printf("Arg <%s>\n", arg);
	result = 0;
	if (arg[0] == 's')
		result = chk_swap(a, b, arg);
	else if (arg[0] == 'p')
		result = chk_psoo(a, b, arg);
	else if (arg[0] == 'r')
		if (ft_strlen(arg) == 2)
			result = chk_rota(a, b, arg);
		else
			result = chk_rrot(a, b, arg);
	else if (arg[0] == '+' || arg[0] == '-' || ft_isdigit(arg[0]))
	{
		if (!pss_push(a, ft_atoi(arg)))
			result = 1;
		else
			result = 0;
	}
	else
		result = 0;
	pss_prin(a);
	pss_prin(b);
	return (result);
}
