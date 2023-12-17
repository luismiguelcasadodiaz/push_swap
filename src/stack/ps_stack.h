/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:04:07 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/17 23:45:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/* PS refers to Push Swap.                                                    */
/*                                                                            */
/* I create a special stack implemented with a double linked list aiming to   */
/* simplyfy rotating operation i have to implement.                           */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
#ifndef PS_STACK_H
# define PS_STACK_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_nod
{
	int				num;
	struct s_nod	*next;
	struct s_nod	*prev;
} t_nod;

typedef struct s_pss
{
	t_nod	*top;
	int		biggest;
	int		smallest;
	int		size;
	char	name;
	int		fd;
} t_pss;

t_nod	*nod_init(int num);
void	nod_free(t_nod my_s);

t_pss	*pss_init(void);
short	pss_empt(t_pss *my_s);
int		pss_size(t_pss *my_s);
void	pss_prin(t_pss *my_s);
int		pss_peek(t_pss *my_s);
void	pss_push(t_pss *my_s, int num);
int		pss_pope(t_pss *my_s);
void	pss_swap(t_pss *my_s);
void	pss_swsw(t_pss *one, t_pss *two);
void	pss_psoo(t_pss *one, t_pss *two);
void	pss_rota(t_pss *my_s);
void	pss_roro(t_pss *one, t_pss *two);
void	pss_rrot(t_pss *my_s);
void	pss_rrrr(t_pss *one, t_pss *two);
void	pss_free(t_pss *my_s);

#endif
