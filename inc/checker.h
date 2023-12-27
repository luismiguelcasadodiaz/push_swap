/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:47:44 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/27 09:11:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# include "libft.h"
# include "ft_printf.h"
# include "libpss.h"

void	chk_init(int *i, t_pss *a, t_pss *b, int *all_OK);
int	chk_trea(char	*arg, t_pss *a, t_pss *b);
int	chk_swap(t_pss *a, t_pss *b);
int	chk_push(t_pss *a, t_pss *b);
int	chk_rota(t_pss *a, t_pss *b);
#endif
