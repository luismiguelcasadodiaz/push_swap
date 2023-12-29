/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argpar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:54:52 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/28 20:31:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARGPAR_H
# define ARGPAR_H
# include "libpss.h"
# include "libft.h"

int	arg_seen(int num, t_pss *my_s);
int	arg_range_int(char *arg, int *my_int);
int	arg_digits(char *arg);
t_pss	*arg_ok(int argc, char **argv);
#endif

