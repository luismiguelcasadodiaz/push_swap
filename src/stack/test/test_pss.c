/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/26 18:10:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*a;
	t_pss	*b;

	a = pss_init('a');
	b = pss_init('b');
//	pss_prin(a); pss_prin(b);
	pss_push(a, 86);
	pss_push(a, 99);
	pss_push(a, 118);
	pss_push(a, 12);
	pss_push(a, 87);
//	pss_prin(a); pss_prin(b);
	pss_rrot(a, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_psoo(b, a, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_psoo(b, a, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_rota(a, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_swap(a, PRINTME);
// /	pss_prin(a); pss_prin(b);
	pss_psoo(a, b, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_psoo(a, b, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_rrot(a, PRINTME);
//	pss_prin(a); pss_prin(b);
	pss_free(a);
	pss_free(b);
	return (0);
}
