/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:40:30 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/26 11:42:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	max_min(int num, int *min, int *max)
{
	if ((*min == INT_MIN) && (*max == INT_MAX))
	{
		*min = num;
		*max = num;
	}
	else
	{
		if (num < *min)
			*min = num;
		if (*max < num)
			*max = num;
	}
}
