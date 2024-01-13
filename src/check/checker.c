/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:32:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	main(int argc, char **argv)
{
	t_pss	*a;
	t_pss	*b;
	int		all_ok;

	if (argc == 1)
		return (0);
	all_ok = 1;
	a = arg_ok(argc, argv);
	if (a)
	{
		b = pss_init('b');
		all_ok = chk_read(a, b);
		if (!all_ok)
			ft_printf("Error\n");
		else if (pss_isor(a) && pss_empt(b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		pss_free(b);
		pss_free(a);
	}
	else
		ft_printf("Error\n");
	return (0);
}
