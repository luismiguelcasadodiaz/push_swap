/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/26 12:36:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"
#include "libft.h"

void	ps_sor3(t_pss *a)
{
	int	bott;
	int	peek;
	int	maxi;
	int	mini;

	peek = pss_peek(a);
	bott = pss_bott(a);
	maxi = pss_bign(a);
	mini = pss_sman(a);
	if (bott == maxi && peek != mini)
		pss_swap(a, PRINTME);
	else if (bott == mini && peek != maxi)
		pss_rrot(a, PRINTME);
	else if (bott == mini && peek == maxi)
	{
		pss_swap(a, PRINTME);
		pss_rrot(a, PRINTME);
	}
	else if (bott != mini && peek == maxi)
		pss_rota(a, PRINTME);
	else if (bott != maxi && peek == mini)
	{
		pss_swap(a, PRINTME);
		pss_rota(a, PRINTME);
	}
}
int	main(int ac, char **av)
{
	t_pss	*a;
	t_pss	*b;
	t_cost	c;
	int		i;
	
	ft_printf("------- Testing allowed operations -------\n");
	a = pss_init('a');
	b = pss_init('b');
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	while (ac > 1)
	{

		pss_push(a, ft_atoi(av[ac - 1]), 0);
		ac--;
	}
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_mkid(a);
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_psoo(b, a, PRINTME);
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_psoo(b, a, PRINTME);
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	i = pss_size(a);
	while (i > 3)
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
	ps_sor3(a);
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	while (!pss_empt(b))
	{
		if ((a->sid < b->top->idx) && (b->top->idx < a->bid))
				pss_extr(pss_nmtp(b->top->idx , a), a,  &c.dira, &c.mova);
		else
				pss_extr(pss_nmtp(a->sid, a), a,  &c.dira, &c.mova);

		if (c.mova !=0)
		{
			if (c.dira == 'f')
				pss_nrot(a, c.mova);
			else
				pss_nrro(a, c.mova);
		}
		pss_psoo(a, b, PRINTME);
		pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	}
	// final rotation to sitauta minim on top
	pss_extr(pss_deep(a->sid, a), a,  &c.dira, &c.mova);
	if (c.mova !=0)
	{
		if (c.dira == 'f')
			pss_nrot(a, c.mova);
		else
			pss_nrro(a, c.mova);
	}
	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
