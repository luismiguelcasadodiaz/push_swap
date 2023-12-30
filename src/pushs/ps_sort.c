/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:59:32 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/30 12:35:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_sort(t_pss *a, t_pss *b)
{
	if (a->siz == 2)
		ps_sor2(a);
	if (a->siz == 3)
		ps_sor3(a);
	if (a->siz == 4)
		ps_sor4(a, b);
	if (a->siz == 5)
		ps_sor5(a, b);
}
