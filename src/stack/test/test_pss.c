/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 22:18:35 by luicasad         ###   ########.fr       */
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
	
//	ft_printf("------- Testing allowed operations -------\n");
	a = pss_init('a');
	b = pss_init('b');
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	while (ac > 1)
	{

		pss_push(a, ft_atoi(av[ac - 1]), 0);
		ac--;
	}
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_mkid(a);
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_psoo(b, a, PRINTME);
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_psoo(b, a, PRINTME);
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	i = pss_size(a);
	while (i > 3)
	{
		c = pss_chea(a, b);
		if (c.roro)
			pss_nror(a, b, c.roro);
		if (c.rrrr)
			pss_nrrr(a, b, c.rrrr);
		if (c.mova)
			pss_nrot(a, c.mova);
		if (c.rmva)
			pss_nrro(a, c.rmva);
		if (c.movb)
			pss_nrot(b, c.movb);
		if (c.rmvb)
			pss_nrro(b, c.rmvb);

		//ft_printf("idx = %d, deepa = %d, directiona = %c, movesa = %d ", c.idx, pss_deep(c.idx, a), c.dira, c.mova);
		//ft_printf("deepb = %d, directionb = %c, movesb = %d\n",  pss_nmtp(c.idx, b), c.dirb, c.movb);
		pss_psoo(b, a, PRINTME);
//		pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
		i--;
	}
	pss_ttop(b, b->bid);
	/*pss_extr(pss_deep(b->bid, b), b,  &c.dirb, &c.movb);
	if (c.movb !=0)
	{
		if (c.dirb == 'f')
			pss_nrot(b, c.movb);
		else
			pss_nrro(b, c.movb);
	}*/
	ps_sor3(a);
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	/*while (!pss_empt(b))
	{
		moves = 0;
		if ((a->sid < b->top->idx) && (b->top->idx < a->bid))
				pss_extr(pss_nmtp(b->top->idx , a), a,  &direction, &moves);
		else if ( (b->top->idx < a->sid) || (a->bid < b->top->idx))
				pss_extr(pss_deep(a->sid, a), a,  &direction, &moves);

		if (moves !=0)
		{
			if (direction == 'f')
				pss_nrot(a, moves);
			else
				pss_nrro(a, moves);
		}
		pss_psoo(a, b, PRINTME);
		pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	}
	*/
	pss_movs(b, a);
	// final rotation to sitauta minim on top
	pss_ttop(a, a->sid);
	/*pss_extr(pss_deep(a->sid, a), a,  &c.dira, &c.mova);
	if (c.mova !=0)
	{
		if (c.dira == 'f')
			pss_nrot(a, c.mova);
		else
			pss_nrro(a, c.mova);
	}
	*/
//	pss_prin(a); pss_prnu(a);	pss_prin(b); pss_prnu(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
