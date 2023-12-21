/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:50:15 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/21 17:10:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_stack.h"
#include <stdlib.h>

/* ************************************************************************** */
/* nod_init() creates an isolated not linked node holding the number num      */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* nod_free() frees the memory allocated to a node. If sure before calling it */
/* that caller function knows where the linked nodes are. Once you call it    */
/* the addresses of linked nodes are lost.                                    */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
/*void	nod_free(t_nod *my_n)
{
	free((void *)my_n);
}*/
