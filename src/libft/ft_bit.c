/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:09:35 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 16:07:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/* ft_bit() checks, inside an integer, the bit position                       */
/*                                                                            */
/* ************************************************************************** */
int	ft_bit(size_t bit_pos, int num)
{
	int	mask;

	mask = 1u << (bit_pos - 1);
	return (mask & num);
}
