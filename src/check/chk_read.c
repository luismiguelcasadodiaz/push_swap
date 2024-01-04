/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:28:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/04 10:34:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	chk_read(t_pss *a, t_pss *b)
{
	short	all_ok;
	pss_psoo(b, a, PRINTME);
	pss_psoo(a, b, PRINTME);
	all_ok = 1;
	return (all_ok);
}
