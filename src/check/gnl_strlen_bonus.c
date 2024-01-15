/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_srtlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:37:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 09:37:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

/*                                                                            */
/* gnl_strlen() returns s'lenght                                              */
/*                                                                            */
size_t	gnl_strlen(char	*s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}
