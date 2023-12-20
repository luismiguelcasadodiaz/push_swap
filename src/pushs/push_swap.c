/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/20 17:51:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../stack/ps_stack.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_printf("%d\n", ft_atoi(argv[i]));
	return (0);
}
