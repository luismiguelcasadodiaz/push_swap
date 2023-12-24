/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpss.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:04:07 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/24 10:55:44 by luicasad         ###   ########.fr       */
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
# include "ft_printf.h"
# define OUTPUT_FD 1

typedef struct s_nod
{
	int				num;
	struct s_nod	*next;
	struct s_nod	*prev;
}	t_nod;

t_nod	*nod_init(int num);
//void	nod_free(t_nod *my_n);

/* ************************************************************************** */
/* The stack is a structure that contains stack atributes.                    */
/*                                                                            */
/* int big holds the biggest  integer in the stack.                           */
/* int sma holds the smallest integer in the stack.                           */
/* int siz holds the number of integers in the stack.                         */
/* chr nam holds the letter that names the stack.                             */
/* int fld holds the file descriptor to print stack data and movements        */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_pss
{
	t_nod	*top;
	int		big;
	int		sma;
	int		siz;
	char	nam;
	int		fld;
}	t_pss;

t_pss	*pss_init(char name);
short	pss_empt(t_pss *my_s);
int	pss_size(t_pss *my_s);
void	pss_mami(t_pss *my_s, int num);
void	pss_prin(t_pss *my_s);
int	pss_peek(t_pss *my_s);
int	pss_push(t_pss *my_s, int num);
int	pss_pope(t_pss *my_s);
void	pss_swap(t_pss *my_s);
void	pss_swsw(t_pss *one, t_pss *two);
void	pss_psoo(t_pss *one, t_pss *two);
void	pss_rota(t_pss *my_s);
void	pss_roro(t_pss *one, t_pss *two);
void	pss_rrot(t_pss *my_s);
void	pss_rrrr(t_pss *one, t_pss *two);
void	pss_free(t_pss *my_s);

#endif