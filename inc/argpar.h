/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argpar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:21:04 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 12:58:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPAR_H
# define ARGPAR_H
# include "libpss.h"

int		arg_seen(int num, t_pss *my_s);
int		arg_range_int(char *arg, int *my_int);
int		arg_digits(char *arg);
t_pss	*arg_ok(int argc, char **argv);
#endif
