/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:02:43 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pss	*a;
	t_pss	*b;

	if (argc == 1)
		return (0);
	a = arg_ok(argc, argv);
	if (a)
	{
		if (!pss_isor(a))
		{
			pss_prnu(a);
			pss_prin(a);
			pss_mkid(a);
			pss_prnu(a);
			pss_prin(a);
			b = pss_init('b');
			ps_sort(a, b);
			pss_prnu(a);
			pss_prin(a);
			pss_free(a);
			pss_free(b);
		}
		else
			pss_free(a);
	}
	else
		ft_printf("Error\n");
	return (0);
}
