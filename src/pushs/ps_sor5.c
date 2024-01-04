/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sor5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:08:13 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 14:06:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
/* ps_sor5() sort a 5-element stack                                           */
/*                                                                            */
/* 1.- Pass 2 elements to stack b                                             */
/* 2.- Sort 3 elemnets of stack a                                             */
/* 3.- from stack b add the 4th element to stack a                            */
/* 4.- From stack b add the 5th element to stack a                            */
/*                                                                            */
/* ************************************************************************** */
void	ps_sor5(t_pss *a, t_pss *b)
{
	pss_psoo(b, a, PRINTME);
	pss_psoo(b, a, PRINTME);
	ps_sor3(a);
	ps_add4(a, b);
	ps_add5(a, b);
}
