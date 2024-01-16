/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:58:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 10:36:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

/* get_next_line() returns a line from a file descriptor.                     */
/*                                                                            */
/* GETS                                                                       */
/*  fd : The file descriptor to read from                                     */
/*                                                                            */
/* RETURNS                                                                    */
/*  Read line: correct behavior.                                              */
/*  NULL     : there is nothing else to read, or an error occurred            */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/* Automatic Variables                                                        */
/*  STATIC read_buf to keep read bytes not yet delivered from call to call    */
/*  read_bytes to keep amount of bytes read from file.                        */
/* *line to partially return buffer as long a newline is found.               */
/*                                                                            */
/*  A infinite loop starts analysing the buffer trying to find a newline      */
/*  inside.                                                                   */
/*                                                                            */
/*  if a newline is found retunrs the line.                                   */
/*  if not reads from the file.                                               */
/*                                                                            */
/*  Reading file retursn 3 possible situation diferenciated thru read_bytes   */
/*                                                                            */
/*  when read_bytes == -1 an error reading file happened:                     */
/*            release line                                                    */
/*            release buffer                                                  */
/*            returns NULL                                                    */
/*                                                                            */
/*  when read_bytes == 0, nothing else to read. wha have two cases:           */
/*                                                                            */
/*    buffer is empty:                                                        */
/*    		 release buffer                                                   */
/*    		 return NULL                                                      */
/*                                                                            */
/*    buffer with leftovers                                                   */
/*           flush the buffer                                                 */
/*                                                                            */
char	*get_next_line(int fd)
{
	static char	*read_buf;
	ssize_t		read_bytes;
	char		*line;

	while ((0 <= fd && fd <= FOPEN_MAX) && (BUFFER_SIZE > 0))
	{
		line = gnl_buff_analisis(&read_buf);
		if (line)
			return (line);
		read_buf = gnl_read_to_buff(fd, read_buf, &read_bytes);
		if (!read_buf && (read_bytes == -1))
		{
			free(line);
			return (gnl_my_free(&read_buf));
		}
		if (!read_buf && (read_bytes == 0))
			return (gnl_my_free(&read_buf));
		if (read_buf && (read_bytes == 0))
			return (gnl_buff_flush(&read_buf));
	}
	return (NULL);
}
