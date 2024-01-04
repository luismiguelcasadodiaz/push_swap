/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:56:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 16:08:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

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
			pss_push(c, num);
	}
	if (all_ok)
		return (pss_reve(c));
	pss_free(c);
	return (NULL);
}
