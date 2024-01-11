/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_digi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:57:56 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 10:58:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

/* ************************************************************************** */
/* arg_digits() verifies that al chars in arg are either +-0123456789.        */
/*                                                                            */
/* OPERATES:                                                                  */
/* Set the hypothesis that arg it is ok.                                      */
/*                                                                            */
/* evaluates if first char of argument is +-0..9                              */
/* Loops the argument string while each char validates against   0123456789   */
/*                                                                            */
/* RETURNS:                                                                   */
/* 1 if all char are all ok, 0 otherwise.                                     */
/* ************************************************************************** */
static int	check(char c)
{
	return ((c == '+') || (c == '-') || ft_isdigit(c));
}

int	arg_digits(char	*arg)
{
	int	i;
	int	ok;

	i = 0;
	if (((arg[i] == '+') || (arg[i] == '-')) && arg[i + 1] == '\0')
		return (0);
	ok = 1;
	ok = ok && check(arg[i++]);
	while (ok && arg[i] != '\0')
		ok = ok && ft_isdigit(arg[i++]);
	return (ok);
}
