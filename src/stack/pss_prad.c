/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:01:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 16:24:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

void	pss_prad(t_pss *a, t_pss *b, ssize_t bit)
{
	ssize_t	loops;

	loops = pss_size(a);
	while (loops)
	{
	//	ft_printf("<%d>[%d]", pss_peek_idx(a), ft_bit(bit, pss_peek_idx(a)));
		if (ft_bit(bit, pss_peek_idx(a)))
			pss_rota(a, PRINTME);
		else
			pss_psoo(b, a, PRINTME);
		loops--;
	}
}
