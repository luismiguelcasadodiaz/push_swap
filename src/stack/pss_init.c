/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:05:08 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/31 08:54:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"

t_pss	*pss_init(char name)
{
	t_pss	*stack;

	stack = (t_pss *)malloc(sizeof(t_pss));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->big = 0;
	stack->sma = 0;
	stack->siz = 0;
	stack->nam = name;
	stack->fld = OUTPUT_FD;
	return (stack);
}
