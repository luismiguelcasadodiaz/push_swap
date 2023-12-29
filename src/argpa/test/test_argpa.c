/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argpa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/29 08:45:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"
#include "argpar.h"

int	main(int argc, char **argv)
{
	t_pss	*c;

	c = arg_ok(argc, argv);
	if (c)
	{	pss_prin(c);
		pss_free(c);
	}
	else
		ft_printf("Error\n");
	return (0);
}
