/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_mkid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:40:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:00:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

void	pss_mkid(t_pss *s)
{
	t_nod	*ex_node;
	t_nod	*in_node;
	short	ex_end;
	short	in_end;

	ex_end = 0;
	ex_node = s->top;
	while (!ex_end)
	{
		ex_end = (ex_node->next == s->top);
		in_end = 0;
		in_node = ex_node;
		while (!in_end)
		{
			in_end = (in_node->next == ex_node);
			if (in_node->num < ex_node->num)
				ex_node->idx++;
			in_node = in_node->next;
		}
		ex_node = ex_node->next;
	}
}
