/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read_to_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:42:47 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 09:35:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* gnl_read_to_buff() joins existing buffer and read bytes from file          */
/*                                                                            */
/* GETS                                                                       */
/*  fd : The file descriptor to read from                                     */
/*  *read_buf : A buffer to concat in the read bytes from fd                  */
/*  *read_bytes: a by reference integer to return file end condition          */
/*                                                                            */
/* RETURNS                                                                    */
/*  The new_buf resulting from the join of read_buf + read_raw                */
/*                                                                            */
/* RETURNS THRU ARGUMENTS                                                     */
/*  The number of bytes read.                                                 */
/*  - A positive integer >0 normal behaviour.                                 */
/*  - Zero when end of file and no more bytes to read remain in fd.           */
/*  - Negative when other problems with fd.                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*                                                                            */
/* Automatic Variables                                                        */
/*  *new_buf keeps read_buf + read_raw and returns it.                        */
/*  *read_raw to keep read bytes from file descriptor.                        */
/*                                                                            */
/* Allocates memory to fill in with bytes read from file.                     */
/*                                                                            */
/* when reading from file fails cause end or file (read_bytes == 0)           */
/*     deallocates memory used for reading read_raw                           */
/*     returns unchanged read_buf.                                            */
/*                                                                            */
/* when reading from file fails cause other error (read_bytes == -1)          */
/*     deallocates memory used for reading read_raw                           */
/*     returns NULL                                                           */
/*                                                                            */
/* when reading from file is OK                   (read_bytes > 0  )          */
/*     null terminated read_raw                                               */
/*     append it to read_buf                                                  */
/*                                                                            */
/*     deallocate memory used for reading read_raw                            */
/*                                                                            */
/*     when Join fails return NULL                                            */
/*                                                                            */
/*     Deallocate obsolete read_buf                                           */
/*                                                                            */
/*     Retunrs Join read_buf + read_raw                                       */
/*                                                                            */
/* TAKE AWAYS                                                                 */
/*                                                                            */
/*   if something fails release strings passed by value like char *read_buf   */
/*                                                                            */
/*                                                                            */

char	*gnl_read_to_buff(int fd, char	*read_buf, ssize_t *read_bytes)
{
	char		*read_raw;
	char		*new_buf;

	read_raw = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_raw == NULL)
		return (gnl_my_free(&read_buf));
	*read_bytes = read(fd, read_raw, BUFFER_SIZE);
	if (*read_bytes <= 0)
	{
		gnl_my_free(&read_raw);
		if (*read_bytes == -1)
			return (gnl_my_free(&read_buf));
		return (read_buf);
	}
	read_raw[*read_bytes] = '\0';
	new_buf = gnl_join(read_buf, read_raw);
	gnl_my_free(&read_raw);
	if (new_buf == NULL)
		return (NULL);
	gnl_my_free(&read_buf);
	return (new_buf);
}
