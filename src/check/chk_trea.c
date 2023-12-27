/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_trea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:00:44 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 09:25:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* ************************************************************************** */
/* chk_trea() analyses the argument. if it is a num, push it. it it is a move */
/*            Rexecutes the move.                                             */
/* ************************************************************************** */
int	chk_trea(char *arg, t_pss *a, t_pss *b)
{
	if (arg[1] == 's')
		result = chk_swap(a, b);
	else if (arg[1] == 'p')
		result = chk_push(a, b);
	else if (arg[1] == 'r')
		result = chk_rota(a, b);
	else if (arg[1] == '+' || arg[1] == '-' || ft_isdigit(arg[1])
		result = 
		if (!pss_push(a, ft_atoi(arg))
			result = 1;
		else
			result = 0;
	//TODO check what pss_push reuturns
	else
		result = 0;
	return (result);
}

