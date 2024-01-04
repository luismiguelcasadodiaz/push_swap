/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 19:51:32 by luicasad         ###   ########.fr       */
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
	//		pss_prin(a);
			b = pss_init('b');
			ps_sort(a, b);
	//		pss_prin(a);
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
