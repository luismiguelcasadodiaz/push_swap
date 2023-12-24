/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:29:20 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/24 16:29:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libpss.h"
#include "ft_printf.h"

int	main(void)
{
	t_pss	*s;

	s = pss_init('c');
	pss_prin(s);
	pss_push(s, 3);
	pss_prin(s);
	pss_push(s, -3);
	pss_prin(s);
	pss_push(s, 53);
	pss_prin(s);
	pss_push(s, 33);
	pss_prin(s);
	ft_printf("poped %d\n", pss_pope(s));
	pss_prin(s);
	ft_printf("poped %d\n", pss_pope(s));
	pss_prin(s);
	pss_free(s);
	return (0);
}
