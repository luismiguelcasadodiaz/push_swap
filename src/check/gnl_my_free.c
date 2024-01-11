/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_my_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:30:59 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 09:45:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* gnl_my_free() releases memory, sets pointer to null ans returns null.      */
/*                                                                            */
/* It is a helper function that saves me lines of code to pass norminette     */
/*                                                                            */
char	*gnl_my_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
