/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_prin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 08:19:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:33:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	show_char(char c, short times)
{
	while (times)
	{
		write(1, &c, 1);
		times--;
	}
}

void	chk_prin(t_pss *a, t_pss *b)
{
	int	total;
	int	w_width;
	int	a_bar;
	int	b_bar;

	w_width = 40;
	total = a->siz + b->siz;
	a_bar = w_width * a->siz / total;
	show_char('|', 1);
	show_char(a->nam, 1);
	show_char('|', 1);
	show_char('*', a_bar);
	show_char(' ', w_width - a_bar);
	b_bar = w_width * b->siz / total;
	show_char('|', 1);
	show_char(b->nam, 1);
	show_char('|', 1);
	show_char('*', b_bar);
	show_char(' ', w_width - b_bar);
	show_char('|', 1);
	show_char('\n', 1);
}
