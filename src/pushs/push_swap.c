/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/28 21:01:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include "libpss.h"
#include "argpar.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	min;
	int	max;
	int 	num;
	t_pss	*c;

	c = arg_ok(argc, argv);

	pss_prin(c);
	min = INT_MAX;
	max = INT_MIN;
	num = 0;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i++]);
		max_min(num, &min, &max);
		ft_printf("%d\n", num);
	}
	ft_printf("En el rango (%d..%d) hay %d enteros\n", min, max, max - min);
	return (0);
}
