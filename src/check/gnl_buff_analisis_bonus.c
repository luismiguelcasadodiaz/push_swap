/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buff_analisis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:49:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 10:09:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* gnl_buff_analisis() splits buffer by first newline  in line and new_buf    */
/*                                                                            */
/* GETS                                                                       */
/*  **read_buf : A passed by reference buffer to split it by first newline    */
/*                                                                            */
/* RETURNS                                                                    */
/*  line : string containing read_buf initial chars till newline included     */
/*                                                                            */
/* RETURNS THRU by reference ARGUMENTS                                        */
/*  **read_buf : buffer where initial chars and newline included were removed */
/*                                                                            */
/*  OPERATES                                                                  */
/*                                                                            */
/*  When read_buf is empty ,nothing to analyze,  return null.                 */
/*                                                                            */
/*  Calculate read_buf lenght and find first new line.                        */
/*                                                                            */
/*  When no newline exist (ret == -1) returns NULL.                           */
/*                                                                            */
/*  Extract line to return from buffer init to newline position included.     */
/*                                                                            */
/*  When malloc fails returns NULL.                                           */
/*                                                                            */
/*  Extract remaining buffer to new_buf.                                      */
/*                                                                            */
/*  ATTENTION: gnl_substr returns NULL in two situations:                     */
/*     Malloc fails.                                                          */
/*     New line is at buffer end so new_buffer has to be empty                */
/*     This is the reason for !new_buf && (buf_len - (ret + 1))               */
/*                                        |--------v-----------|              */
/*                                        if != 0 malloc fails                */
/*                                        if == 0 empty new_buf               */
/*                                                                            */
/*  when malloc fails free previous extracted line and returns NULL.          */
/*                                                                            */
/*  Frees older buffer and assign to buffer new buffer.                       */
/*                                                                            */
/*  returns extractes line including a new line.                              */
/*                                                                            */
char	*gnl_buff_analisis(char	**read_buf)
{
	char	*line;
	char	*new_buf;
	ssize_t	buf_len;
	ssize_t	ret;

	if (*read_buf == NULL)
		return (NULL);
	buf_len = gnl_strlen_and_nl(&ret, read_buf[0]);
	if (ret == -1)
		return (NULL);
	line = gnl_substr(*read_buf, 0, (ret + 1));
	if (!line)
		return (NULL);
	new_buf = gnl_substr(*read_buf, (ret + 1), (buf_len - (ret + 1)));
	if (!new_buf && (buf_len - (ret + 1)))
		return (gnl_my_free(&line));
	free(*read_buf);
	*read_buf = new_buf;
	return (line);
}
