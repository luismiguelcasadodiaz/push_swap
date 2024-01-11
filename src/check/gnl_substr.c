/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:33:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 09:58:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* gnl_substr () returns a substring of size len from a string starting in    */
/* the start position                                                         */
/*                                                                            */
/* It is a simplification form FT_substr. Calling function is responsible for */
/*   A) do not request start in a position bigger than str's length           */
/*   B) do not request len character greater than the difference between      */
/*      str's length minus start position.                                    */
/* GETS                                                                       */
/*  *read_buf : The string to extract from.                                   */
/*  start : Substring initial position.                                       */
/*  len   : Size of string to return.                                         */
/*                                                                            */
/* RETURNS                                                                    */
/*  Substring: correct behavior.                                              */
/*  NULL     : When ENOMEM or len = 0.                                        */
/*                                                                            */
/* OPERATES                                                                   */
/*   When len = 0 returns NULL as there are no requires chars to extract.     */
/*                                                                            */
/*   Allocates memory for chars to extract and return in a null terminated    */
/*   string.                                                                  */
/*                                                                            */
/*   Copies len chars from read_buf to line and null terminate it.            */
/*                                                                            */
/*   returns line.                                                            */
/*                                                                            */
char	*gnl_substr(char *read_buf, unsigned int start, size_t len)
{
	char	*line;
	size_t	idx;

	if (len == 0)
		return (NULL);
	line = (char *)malloc(len + 1);
	if (!line)
		return (gnl_my_free(&line));
	idx = 0;
	while (idx < len)
	{
		line[idx] = read_buf[start + idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}
