/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:56:37 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 08:57:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	chk_init(int *i, t_pss *a, t_pss *b, int *all_OK)
{
	*i = 1;
	*all_OK = 1;
	a = pss_init('a');
	b = pss_init('b');
}

