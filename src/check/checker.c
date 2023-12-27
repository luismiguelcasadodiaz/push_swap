/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:37 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 09:22:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	main(int argc, char **argv)
{
	int	i;
	t_pss	*a;
	t_pss	*b;
	int	all_OK;

	chk_init(&i, a, b, &all_OK);
	while (i < argc & all_OK)
		all_OK = chk_trea(argv[1], a, b)
	if (all_OK)
		if (pss_isor(a) & pss_empt(b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	else
		ft_print("Error\n");
	return (0);
}
