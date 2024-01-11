/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 18:24:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	main(int argc, char **argv)
{
	int		i;
	t_pss	*a;
	t_pss	*b;
	int		all_ok;

	if (argc == 1)
		return (0);
	i = 1;
	all_ok = 1;
	//chk_init(&i, &a, &b, &all_ok);
	a = arg_ok(argc, argv);
	if (a)
	{	
		b = pss_init('b');
		all_ok = chk_read(a, b);
		if (all_ok)
			if (pss_isor(a) && pss_empt(b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		else
			ft_printf("Error\n");
		pss_free(b);
	}
	else
		ft_printf("Error\n");
	pss_free(a);
	return (0);
}
