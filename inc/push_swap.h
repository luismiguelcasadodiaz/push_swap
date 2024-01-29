/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:21:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/30 00:21:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "libpss.h"
# include "argpar.h"

void	ps_sort(t_pss *a, t_pss *b);
void	ps_sor2(t_pss *a);
void	ps_sor3(t_pss *a);
void	ps_sor4(t_pss *a, t_pss *b);
void	ps_sor5(t_pss *a, t_pss *b);
void	ps_add4(t_pss *a, t_pss *b);
void	ps_add5(t_pss *a, t_pss *b);
void	ps_radi(t_pss *a, t_pss *b);
void	ps_turk(t_pss *a, t_pss *b);

#endif
