/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:06:53 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 22:23:52 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpss.h"
#include "ft_printf.h"

void	cos_show(t_cost s)
{
	ft_printf("c0{idx:%d,", s.idx);
	ft_printf("  mov:%d,", s.mov);
	ft_printf(" mova:%d,", s.mova);
	ft_printf(" rmva:%d,", s.rmva);
	ft_printf(" movb:%d,", s.movb);
	ft_printf(" rmvb:%d,", s.rmvb);
	ft_printf(" roro:%d,", s.roro);
	ft_printf(" rrrr:%d}\n", s.rrrr);
}
