/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buff_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:52:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 10:10:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

/* gnl_buff_flush() Empties the buffer                                        */
/*                                                                            */
/* GETS                                                                       */
/*  **read_buf : A passed by reference buffer to empty it and return leftover */
/*                                                                            */
/* RETURNS                                                                    */
/*  line : string containing read_buf letfovers                               */
/*                                                                            */
/* RETURNS THRU by reference ARGUMENTS                                        */
/*  **read_buf : buffer settle to NULL after empty the buffe                  */
/*                                                                            */
/*  OPERATES                                                                  */
/*                                                                            */
/*  When read_buf is empty ,nothing to analyze,  return null.                 */
/*                                                                            */
/*  Calculate read_buf lenght.                                                */
/*                                                                            */
/*                                                                            */
/*  allocate memory for a returning line wiht buffer content.                 */
/*                                                                            */
/*  When malloc fails returns NULL after releasing buffer.                    */
/*                                                                            */
/*  Copies buffer content into returning line.                                */
/*                                                                            */
/*  null terminate retunrning line.                                           */
/*                                                                            */
/*  Frees older buffer.                                                       */
/*                                                                            */
/*  returns extracted line.                                                   */
/*                                                                            */
char	*gnl_buff_flush(char **read_buf)
{
	char	*line;
	size_t	i;

	if (*read_buf == NULL)
		return (gnl_my_free(read_buf));
	i = gnl_strlen(read_buf[0]);
	line = (char *)malloc(i + 1);
	if (!line)
		return (gnl_my_free(read_buf));
	i = 0;
	while (read_buf[0][i] != '\0')
	{
		line[i] = read_buf[0][i];
		i++;
	}
	line[i] = '\0';
	gnl_my_free(read_buf);
	return (line);
}
