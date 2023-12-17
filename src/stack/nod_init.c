/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:50:15 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/17 23:42:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_stack.h"
#include <stdlib.h>

t_nod	*nod_init(int num)
{
	t_nod	*node;

	node = (t_nod *)malloc(sizeof(t_nod));
	if (node != NULL)
	{
		node->num = num;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
