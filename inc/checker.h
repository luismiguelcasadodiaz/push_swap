/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:22:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/09 09:23:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include "ft_printf.h"
# include "libpss.h"
# include "argpar.h"

void	hk_init(int *i, t_pss **a, t_pss **b, int *all_OK);
int		chk_trea(char	*arg, t_pss *a, t_pss *b);
int		chk_swap(t_pss *a, t_pss *b, char *move);
int		chk_psoo(t_pss *a, t_pss *b, char *move);
int		chk_rota(t_pss *a, t_pss *b, char *move);
int		chk_rrot(t_pss *a, t_pss *b, char *move);
int		chk_read(t_pss *a, t_pss *b);
#endif
