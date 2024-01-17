/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_prad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:01:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/17 12:21:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include "libft.h"

void	pss_prad(t_pss *a, t_pss *b, ssize_t bit)
{
	ssize_t	loops;

	loops = pss_size(a);
	while (loops)
	{
		if (ft_bit(bit, pss_peek_idx(a)))
			pss_rota(a, PRINTME);
		else
			pss_psoo(b, a, PRINTME);
		loops--;
	}
}
