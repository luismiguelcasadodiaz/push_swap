/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/21 12:30:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*a;
	t_pss	*b;
	int		i;
	
	ft_printf("------- Testing allowed operations -------\n");
	a = pss_init('a');
	b = pss_init('b');
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_push(a, 3, 0);
	pss_push(a, 2, 0);
	pss_push(a, 1, 0);
	pss_push(a, 6, 0);
	pss_push(a, 5, 0);
	pss_push(a, 4, 0);
	pss_push(a, 9, 0);
	pss_push(a, 8, 0);
	pss_push(a, 0, 0);
	pss_push(a, 7, 0);
	pss_push(a, -3, 0);
	pss_push(a, -2, 0);
	pss_push(a, -1, 0);
	pss_push(a, -6, 0);
	pss_push(a, -5, 0);
	pss_push(a, -4, 0);
	pss_push(a, -9, 0);
	pss_push(a, -8, 0);
	pss_push(a, -7, 0);
	pss_mkid(a);
	pss_psoo(b, a, PRINTME);
	pss_psoo(b, a, PRINTME);
	i = pss_size(a);
	while (i)
	{
		ft_printf("idx = %d, deep = %d\n", i, pss_deep(i, a));
		i--;
	}
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
