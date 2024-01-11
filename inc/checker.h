/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:22:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/11 13:16:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include "ft_printf.h"
# include "libpss.h"
# include "argpar.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

size_t	gnl_strlen(char	*s);
size_t	gnl_strlen_and_nl(ssize_t *pos, char	*s);
char	*gnl_substr(char *str, unsigned int start, size_t len);
char	*gnl_join(char *buf, char *raw);
char	*gnl_read_to_buff(int fd, char	*read_buf, ssize_t *read_bytes);
char	*gnl_buff_analisis(char	**read_buf);
char	*gnl_buff_flush(char **read_buf);
char	*get_next_line(int fd);
char	*gnl_my_free(char **ptr);

void	chk_init(int *i, t_pss **a, t_pss **b, int *all_OK);
int		chk_trea(char	*arg, t_pss *a, t_pss *b);
int		chk_swap(t_pss *a, t_pss *b, char *move);
int		chk_psoo(t_pss *a, t_pss *b, char *move);
int		chk_rota(t_pss *a, t_pss *b, char *move);
int		chk_rrot(t_pss *a, t_pss *b, char *move);
int		chk_read(t_pss *a, t_pss *b);
#endif
