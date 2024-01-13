/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpss.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:04:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/13 18:37:56 by luicasad         ###   ########.fr       */
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
#ifndef LIBPSS_H
# define LIBPSS_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"
# define OUTPUT_FD 1
# define PRINTME 1
# define NOPRINT 0

/* ************************************************************************** */
/* The node is a structure that contains:                                     */
/*                                                                            */
/* int num holds integer value to sor                                         */
/* int idx holds the future position of num inside a sorted stack             */
/* *next the pointer to next node.                                            */
/* *prev the pointet to previous node.                                        */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_nod
{
	int				num;
	ssize_t			idx;
	struct s_nod	*next;
	struct s_nod	*prev;
}	t_nod;

t_nod	*nod_init(int num, ssize_t idx);
void	nod_free(t_nod *my_n);

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
void	pss_free(t_pss *my_s);
short	pss_empt(t_pss *my_s);
int		pss_size(t_pss *my_s);
int		pss_sman(t_pss *my_s);
int		pss_bign(t_pss *my_s);
int		pss_mini(t_pss *my_s);
int		pss_maxi(t_pss *my_s);
/* ************************************************************************** */
/* pss_mami() updates min and max according the last pushed num.              */
/* ************************************************************************** */
void	pss_mami(t_pss *my_s, int num, char c);
/* ************************************************************************** */
/* pss_prin() Prints indexes of stack's nodes                                 */
/* ************************************************************************** */
void	pss_prin(t_pss *my_s);
/* ************************************************************************** */
/* pss_prnu() Prints values of stack's nodes                                  */
/* ************************************************************************** */
void	pss_prnu(t_pss *my_s);
/* ************************************************************************** */
/* pss_have() Checks if stack has the value num                               */
/* ************************************************************************** */
int		pss_have(t_pss *my_s, int num);
/* ************************************************************************** */
/* pss_peek() Returns stack's top-node's value                                */
/* ************************************************************************** */
int		pss_peek(t_pss *my_s);
/* ************************************************************************** */
/* pss_peek_idx() Returns stack's top-node's index                            */
/* ************************************************************************** */
int		pss_peek_idx(t_pss *my_s);
/* ************************************************************************** */
/* pss_unpe() Returns stack's under-top-node's value                          */
/* ************************************************************************** */
int		pss_unpe(t_pss *my_s);
/* ************************************************************************** */
/* pss_ovbo() Returns stack's over-bottom-node's value                        */
/* ************************************************************************** */
int		pss_ovbo(t_pss *my_s);
/* ************************************************************************** */
/* pss_bott() Returns stack's bottom-node's value                             */
/* ************************************************************************** */
int		pss_bott(t_pss *my_s);
/* ************************************************************************** */
/* pss_isor() checks if stack's values are stored in ascendan order           */
/* ************************************************************************** */
int		pss_isor(t_pss *my_s);
t_pss	*pss_reve(t_pss *my_s);
int		pss_push(t_pss *my_s, int num, ssize_t idx);
int		pss_pope(t_pss *my_s, int *num, ssize_t *idx);
void	pss_swap(t_pss *my_s, int printme);
void	pss_swsw(t_pss *one, t_pss *two, int printme);
void	pss_psoo(t_pss *dst, t_pss *ori, int printme);
void	pss_rota(t_pss *my_s, int printme);
void	pss_roro(t_pss *one, t_pss *two, int printme);
void	pss_rrot(t_pss *my_s, int printme);
void	pss_rrrr(t_pss *one, t_pss *two, int printme);
void	pss_nrot(t_pss *my_s, int n);
void	pss_nrro(t_pss *my_s, int n);
/* ************************************************************************** */
/* pss_mkid() makes(calculates) the future positions in a sorted stack        */
/* ************************************************************************** */
void	pss_mkid(t_pss *my_s);
/* ************************************************************************** */
/* pss_pall() pushes all nodes from stack two(ori) to stack one (dst)         */
/* ************************************************************************** */
void	pss_pall(t_pss *one, t_pss *two);
void	pss_prad(t_pss *one, t_pss *two, ssize_t bit);

#endif
