/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:56:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 12:47:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_pars.c                                                          .*/
/*.@brief arg_ok()i if arguments as unique integers that pushes into stacks. .*/
/*.                                                                          .*/
/*.@param[in] argc: number of arguments to verify.          .                .*/
/*.@param[in] argv: table  of arguments to verifi .                          .*/
/*.                                                                          .*/
/*.@returns a stack with first argument on the top when all arguments are    .*/
/*.  ok. Otherwise returns NULL.                                             .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.Creates a stack 'c' to keep the arguments                                 .*/
/*.                                                                          .*/
/*.Set the hypothesis all arguments are ok (all_ok = 1)                      .*/
/*.                                                                          .*/
/*.Loops over the table of arguments verifing requirements:                  .*/
/*. 1.- The argument represents an integer.                                  .*/
/*. 2.- The integer fits in a  "int" type.                                   .*/
/*. 3.- The integer is not in the stack.                                     .*/
/*.                                                                          .*/
/*. if the argument satisfy all 3 requirements, it is pushed into the stack. .*/
/*.                                                                          .*/
/*.After processing all the table, if all arguments passed requirements,     .*/
/*.the arguments order in the stack is reversed to have first argument on    .*/
/*.stack's top and returns it. Otherwise returns NULL                        .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
t_pss	*arg_ok(int argc, char **argv)
{
	int		i;
	int		all_ok;
	int		num;
	t_pss	*c;

	c = pss_init('c');
	i = 1;
	all_ok = 1;
	while (all_ok && i < argc)
	{
		all_ok = all_ok && arg_digits(argv[i]);
		if (all_ok)
			all_ok = all_ok && (arg_range_int(argv[i++], &num));
		if (all_ok)
			all_ok = all_ok && !pss_have(c, num);
		if (all_ok)
			pss_push(c, num, 0);
	}
	if (all_ok)
		return (pss_reve(c));
	pss_free(c);
	return (NULL);
}
