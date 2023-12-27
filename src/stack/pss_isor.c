/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_isor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:33:47 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 08:45:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

int	pss_isor(t_pss	*s)
{
	t_nod	*nod;
	int	num;
	int	result;

	result = 1;
	if (!pss_empt(s))
	{
		nod = s->top;
		num = nod->num;
		while (!end & result)
		{
			end = (nod->next == s->top);
			if (!end)
				result = (num < nod->next->num);
			nod = nod->next;
		}
	}
	return (result);
}
