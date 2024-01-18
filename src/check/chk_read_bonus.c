/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:28:20 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/18 19:07:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <libft.h>

int	chk_read(t_pss *a, t_pss *b)
{
	short	all_ok;
	int		fd;
	short	end_file;
	char	*move;

	all_ok = 1;
	fd = open("/dev/stdin", O_RDONLY);
	end_file = 0;
	while (!end_file)
	{
		move = get_next_line(fd);
		if (move == NULL)
			end_file = 1;
		else
		{
			all_ok = all_ok && chk_trea(move, a, b);
		}
		free(move);
	}
	return (all_ok);
}
