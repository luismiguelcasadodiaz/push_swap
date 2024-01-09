/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:49:44 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 14:21:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	num;
	int	bits;
	int	bit;
	int	mask;

	if (argc != 2)
		ft_putstr_fd("Usage is ./test <num> \n", 1);
	else
	{
		num = ft_atoi(argv[1]);
		if (num > 0)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(num, 1);
		ft_putchar_fd(' ', 1);
		ft_putbits_fd(num, 1);
		ft_putstr_fd(" msb=>  ", 1);
		ft_putnbr_fd(ft_msb(num),1);
		bits = sizeof(int);
		bit = 1;
		while (bit < bits)
		{
			mask = 1u << (bit - 1);
			if (mask && num)
				ft_putchar_fd('1', 1);
			else
				ft_putchar_fd('0', 1);
			bit++;
		}
	}
	return (0);
}
