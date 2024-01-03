/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_digi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:57:56 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:58:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

/* ************************************************************************** */
/* arg_digits() verifies that al chars in arg are either +-0123456789.        */
/*                                                                            */
/* OPERATES:                                                                  */
/* Set the hypothesis that arg it is ok.                                      */
/* Loops the argument string while each char validates against +-0123456789   */
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
	ok = 1;
	while (ok && arg[i] != '\0')
		ok = ok && check(arg[i++]);
	return (ok);
}
