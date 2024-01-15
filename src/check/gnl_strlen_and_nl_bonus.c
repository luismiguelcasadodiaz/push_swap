/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strlen_and_nl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:38:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 09:39:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/* gnl_strlen_and_nl() returns s'lenght and the pos of a newline char in s    */
/*                                                                            */
/* GETS                                                                       */
/*  *read_buf : the buffer to find newline in and to return it length         */
/*  *pos      : integer to return newline posiiton inside read_buf            */
/*                                                                            */
/* RETURNS                                                                    */
/*   read_buf's length                                                        */
/*                                                                            */
/*   THRU passed by reference pos, the position of the newline,-1 otherwise   */
/*                                                                            */
/* OPERATES                                                                   */
/*                                                                            */
/*   set pos to -1  s it is no newline found                                  */
/*                                                                            */
/*                                                                            */
/*   Loops buffer till the end.                                               */
/*                                                                            */
/*   Inside each loop, while not newline found, checks for a newline          */
/*                                                                            */
/*   when the new line was found, recor its posiiton in pos.                  */
/*                                                                            */
/*   returns read_buf's length                                                */
/*                                                                            */
/*                                                                            */
size_t	gnl_strlen_and_nl(ssize_t *pos, char	*read_buf)
{
	ssize_t	i;

	*pos = -1;
	i = 0;
	if (read_buf)
	{
		while (read_buf[i] != '\0')
		{
			if ((read_buf[i] == '\n') && (*pos == -1))
				*pos = i;
			i++;
		}
	}
	return (i);
}
