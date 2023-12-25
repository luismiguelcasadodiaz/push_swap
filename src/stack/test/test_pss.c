/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/25 13:17:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*a;
	t_pss	*b;
	int 	i;

	a = pss_init('a');
	b = pss_init('b');
	pss_prin(a); pss_prin(b);
	pss_push(a, 3);
	pss_prin(a);
	pss_push(a, -3);
	pss_prin(a);
	pss_push(a, 53);
	pss_prin(a);
	pss_push(a, 33);
	pss_prin(a);
	i = 0;
	while (i < 6)
	{
	pss_rrot(s, NOPRINT);
	pss_prin(s);
	pss_rrot(s, NOPRINT);
	pss_prin(s);
	pss_swap(s, NOPRINT);
	pss_prin(s);
	i++;
	}
	pss_pope(s, &i);
	ft_printf("poped %d\n", i);
	pss_prin(s);
	pss_pope(s, &i);
	ft_printf("poped %d\n", i);
	pss_prin(s);
	pss_free(s);
	return (0);
}
