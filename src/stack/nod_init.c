/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:50:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/08 23:32:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include <stdlib.h>

t_nod	*nod_init(int num, ssize_t idx)
{
	t_nod	*node;

	node = (t_nod *)malloc(sizeof(t_nod));
	if (node != NULL)
	{
		node->num = num;
		node->idx = idx;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
