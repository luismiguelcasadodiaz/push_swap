/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_rang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:58:33 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 19:23:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_rang.c                                                          .*/
/*.@brief arg_range_int() check if arg fits in the integer range.            .*/
/*.                                                                          .*/
/*.@param[in]  arg: the string to see if fits inside an integer.             .*/
/*.@param[out] my_int: the value resulting from arg conversion.              .*/
/*.@returns 1 if the argument is inside INT_MIN..INT_MAX, 0 otherwise.       .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.To check, first converts arg to long with ft_atol() from ft_libft.        .*/
/*.                                                                          .*/
/*.@var long arg_num                                                         .*/
/*.Holds the value resulting form convert arg string int a number            .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
int	arg_range_int(char *arg, int *my_int)
{
	long	arg_num;

	arg_num = ft_atol(arg);
	if (INT_MIN <= arg_num && arg_num <= INT_MAX)
	{
		*my_int = (int)arg_num;
		return (1);
	}
	else
		return (0);
}
