/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:09:27 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 19:41:08 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*./file ps_sor3.c                                                           .*/
/*./brief ps_sor3() sorts s 3 numbers stack..                                .*/
/*.                                                                          .*/
/*./param[in]  a: The stack to sort.                                         .*/
/*.                                                                          .*/
/*./details                                                                  .*/
/*.case 1 [2 1 3] bottom == max && peek != min => sa  [1 2 3]<br>            .*/
/*.case 2 [2 3 1] bottom == min && peek != max => rra [1 2 3]<br>            .*/
/*.case 3 [3 2 1] bottom == min && peek == max => sa  [2 3 1] rra [1 2 3]<br>.*/
/*.case 4 [3 1 2] bottom != min && peek == max => ra  [1 2 3]<br>            .*/
/*.case 4 [1 3 2] bottom != max && peek == min => sa  [3 1 2] ra  [1 2 3]    .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Díaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
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
