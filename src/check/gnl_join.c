/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:35:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 09:59:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* gnl_join() joins preffix(buf) with suffix(raw). Both null terminated       */
/*                                                                            */
/* Buf can be empty. The function handles this situation.                     */
/*   A) do not request start in a position bigger than str's length           */
/*   B) do not request len character greater than the difference between      */
/*      str's length minus start position.                                    */
/* GETS                                                                       */
/*  *buf  : The preffix string.                                               */
/*  *raw  : the suffix  string.                                               */
/*                                                                            */
/* RETURNS                                                                    */
/*  preffix + suffix + null-terminator is the normal behaviour                */
/*  NULL     : When ENOMEM.                                                   */
/*                                                                            */
/* OPERATION                                                                  */
/*  set buf_size to zero and navigated it if exists to know its lenght        */
/*  set raw_size to zero and navigated it to know its lenght                  */
/*  allocate memory for resulting string                                      */
/*  use idx to index new, buf and raw. the index in raw is subtractes by      */
/*      buf size                                                              */
/*  copy buf over new                                                         */
/*  copy raw over new after buf                                               */
/*  free both raw and former buf                                              */
/*                                                                            */
char	*gnl_join(char *buf, char *raw)
{
	size_t	buf_size;
	size_t	raw_size;
	size_t	idx;
	char	*newbuf;

	buf_size = gnl_strlen(buf);
	raw_size = gnl_strlen(raw);
	newbuf = (char *)malloc(buf_size + raw_size + 1);
	if (newbuf == NULL)
		return (gnl_my_free(&buf));
	idx = 0;
	while (idx < (buf_size))
	{
		newbuf[idx] = buf[idx];
		idx++;
	}
	while ((idx - buf_size) < raw_size)
	{
		newbuf[idx] = raw[idx - buf_size];
		idx++;
	}
	newbuf[idx] = '\0';
	return (newbuf);
}
