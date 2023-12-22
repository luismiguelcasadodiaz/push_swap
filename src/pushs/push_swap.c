/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/22 13:23:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
// #include "ps_stack.h"
//#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	min;
	int	max;
	int num;

	min = INT_MAX;
	max = INT_MIN;
	num = 0;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i++]);
		//max_min(num, &min, &max);
		ft_printf("%d\n", num);
	}
	ft_printf("En el rango (%d..%d) hay %d enteros\n", min, max, max - min);
	return (0);
}
