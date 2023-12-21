/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/21 09:01:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../src/libft/libft.h"
#include "../../src/ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_printf("%d\n", ft_atoi(argv[i++]));
	return (0);
}
