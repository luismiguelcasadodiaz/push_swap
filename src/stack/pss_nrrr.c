/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss_nrrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:48:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/26 18:33:43 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"

void	pss_nrrr(t_pss *a, t_pss *b, int n)
{
	while (n-- > 0)
		pss_rrrr(a, b, PRINTME);
}
