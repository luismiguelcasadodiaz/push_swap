/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:07:56 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/30 08:54:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_pss *a, t_pss *b)
{
	if (a->siz == 1)
		return ;
	else if (a->siz == 2)
		ps_sor2(a);
	else if (a->siz == 3)
		ps_sor3(a);
	else if (a->siz == 4)
		ps_sor4(a, b);
	else if (a->siz == 5)
		ps_sor5(a, b);
	else
		ps_turk(a, b);
}
