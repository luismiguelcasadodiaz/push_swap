/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:37 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/26 17:47:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include "libpss.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		ft_printf("%d\n", ft_atoi(argv[i++]));
	return (0);
}
