/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/24 17:03:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*a;
	t_pss	*b;
	t_cost	c;
	int		i;
	
	ft_printf("------- Testing allowed operations -------\n");
	a = pss_init('a');
	b = pss_init('b');
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_push(a, 8, 0);
	pss_push(a, 4, 0);
	pss_push(a, 9, 0);
	pss_push(a, 3, 0);
	pss_push(a, 6, 0);
	pss_push(a, 1, 0);
	pss_push(a, 7, 0);
	pss_push(a, 2, 0);
	pss_push(a, 5, 0);
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_mkid(a);
	pss_psoo(b, a, PRINTME);
	if (b->top->idx < a->top->idx)
		pss_psoo(b, a, PRINTME);
	else
	{
		pss_psoo(b, a, PRINTME);
		pss_swap(b, PRINTME);
	}
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	i = pss_size(a);
	while (i)
	{
		c = pss_chea(a, b);
		ft_printf("idx = %d, deepa = %d, directiona = %c, movesa = %d ", c.idx, pss_deep(c.idx, a), c.dira, c.mova);
		ft_printf("deepb = %d, directionb = %c, movesb = %d\n",  pss_nmtp(c.idx, b), c.dirb, c.movb);
		if (c.mova !=0)
		{
			if (c.dira == 'f')
				pss_nrot(a, c.mova);
			else
				pss_nrro(a, c.mova);
		}
		if (c.movb !=0)
		{
			if (c.dirb == 'f')
			{
				pss_nrot(b, c.movb);
				pss_psoo(b, a, PRINTME);
				//pss_nrro(b, c.movb + 1);
			}
			else
			{
				pss_nrro(b, c.movb);
				pss_psoo(b, a, PRINTME);
				//pss_nrot(b, c.movb + 1);
			}
		}
		else
			pss_psoo(b, a, PRINTME);
		pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
		i--;
	}
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
