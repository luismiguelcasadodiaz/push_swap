/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 14:35:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*a;
	t_pss	*b;
	
	ft_printf("------- Testing allowed operations -------\n");
	a = pss_init('a');
	b = pss_init('b');
	pss_prin(a); pss_prin(b);
	pss_push(a, 3);
	pss_push(a, 2);
	pss_push(a, 1);
	pss_push(b, 6);
	pss_push(b, 5);
	pss_push(b, 4);
	pss_prin(a); pss_prin(b);
	pss_swap(a, PRINTME);
	pss_swap(b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_swap(a, PRINTME);
	pss_swap(b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_swsw(a, b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_swsw(a, b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_rota(a, PRINTME);
	pss_rota(b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_rrrr(a, b,  PRINTME);
	pss_prin(a); pss_prin(b);
	pss_rrot(a, PRINTME);
	pss_rrot(b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_roro(a, b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_psoo(b, a, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_psoo(a, b, PRINTME);
	pss_prin(a); pss_prin(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
