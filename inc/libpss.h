/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpss.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:04:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/29 18:05:57 by luicasad         ###   ########.fr       */
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
# define OUTPUT_FD 1
# define PRINTME 1
# define NOPRINT 0

/* ************************************************************************** */
/* The cost is a structure that contains the cost in movements for extracting */
/* idx from stack a and insert it in the right order in stack b.              */
/*                                                                            */
/* ssize_t idx holdis the idx this cost refres toside a sorted stack.         */
/* short mov holds optimiced total moves using roro & rrrr.                   */
/* short mova holds moves (rota/rrot) of a to put idx on the top.             */
/* short movb holds moves (rota/rrot) of b to put on the top idx's next idx.  */
/* char dira holds an 'f' for rota moves or a 'b' for rrot moves of a.        */
/* char dirb holds an 'f' for rota moves or a 'b' for rrot moves of b.        */
/*                                                                            */
/* ************************************************************************** */
typedef struct	s_cost
{
	ssize_t	idx;
	short	mov;
	short	mova;
	short	movb;
	char	dira;
	char	dirb;
	short	rmva;
	short	rmvb;
	short	roro;
	short	rrrr;
}	t_cost;

/* ************************************************************************** */
/* cos_init() sets to zero all struct fields.                                 */
/* ************************************************************************** */
void cos_init(t_cost *c);
/* ************************************************************************** */
/* cos_show() prints all cost fields.                                         */
/* ************************************************************************** */
void cos_show(t_cost c);
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
/* int big holds the biggest  index   in the stack.                           */
/* int sma holds the smallest index   in the stack.                           */
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
	int		bid;
	int		sid;
}	t_pss;

t_pss	*pss_init(char name);
void	pss_free(t_pss *my_s);
short	pss_empt(t_pss *my_s);
int		pss_size(t_pss *my_s);
int		pss_sman(t_pss *my_s);
int		pss_bign(t_pss *my_s);
int		pss_mini(t_pss *my_s);
int		pss_maxi(t_pss *my_s);
ssize_t	pss_imax(t_pss *my_s);
ssize_t	pss_imin(t_pss *my_s);
/* ************************************************************************** */
/* pss_mami() updates min and max according the last pushed num.              */
/* ************************************************************************** */
void	pss_mami(t_pss *my_s, int num, ssize_t idx, char c);
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
int		pss_isori(t_pss *my_s);
t_pss	*pss_reve(t_pss *my_s);
/* ************************************************************************** */
/* pss_push() inserts a new node on top of the stack                          */
/* ************************************************************************** */
int		pss_push(t_pss *my_s, int num, ssize_t idx);
/* ************************************************************************** */
/* pss_pope() Removes an element from top of the stack                        */
/* ************************************************************************** */
int		pss_pope(t_pss *my_s, int *num, ssize_t *idx);
void	pss_swap(t_pss *my_s, int printme);
void	pss_swsw(t_pss *one, t_pss *two, int printme);
void	pss_psoo(t_pss *dst, t_pss *ori, int printme);
void	pss_rota(t_pss *my_s, int printme);
void	pss_nrot(t_pss *my_s, int n);
void	pss_roro(t_pss *one, t_pss *two, int printme);
void	pss_nror(t_pss *one, t_pss *two, int n);
void	pss_rrot(t_pss *my_s, int printme);
void	pss_nrro(t_pss *my_s, int n);
void	pss_rrrr(t_pss *one, t_pss *two, int printme);
void	pss_nrrr(t_pss *one, t_pss *two, int n);
/* ************************************************************************** */
/* pss_mkid() makes(calculates) the future positions in a sorted stack        */
/* ************************************************************************** */
void	pss_mkid(t_pss *my_s);
/* ************************************************************************** */
/* pss_pall() pushes all nodes from stack two(ori) to stack one (dst)         */
/* ************************************************************************** */
void	pss_pall(t_pss *one, t_pss *two);
/* ************************************************************************** */
/* pss_prad() implements one iteration of Radix Sort algorithm                */
/* ************************************************************************** */
void	pss_prad(t_pss *one, t_pss *two, ssize_t bit);
/* ************************************************************************** */
/* pss_deep() returns how many nodes there are above actual idx position      */
/* ************************************************************************** */
ssize_t	pss_deep(ssize_t idx, t_pss *one);
/* ************************************************************************** */
/* pss_nmtp() returns number of moves towards the right positioni             */
/* ************************************************************************** */
short	pss_nmtp(ssize_t idx, t_pss *one);
/* ************************************************************************** */
/* pss_extr() returns optima direction and moves number to extract a node     */
/* ************************************************************************** */
void	pss_extr(ssize_t deep, t_pss *a, char *direction, short *moves);
void	pss_inse(ssize_t deep, t_pss *a, char *direction, short *moves);
t_cost	pss_chea(t_pss *a, t_pss *b);
/* ************************************************************************** */
/* pss_ttop() rotates the stack till idx is in the top                        */
/* ************************************************************************** */
void	pss_ttop(t_pss *a, ssize_t idx);
/* ************************************************************************** */
/* pss_movs() inserts ori's nodes into the ascendadnt ordered stack des       */
/* ************************************************************************** */
void	pss_movs(t_pss *ori, t_pss *des);
/* ************************************************************************** */
/* pss_opti() optimices moves for moving idx from stack a to stack b          */
/* ************************************************************************** */
t_cost	pss_opti(t_pss *a, t_pss *b, ssize_t idx);
/* ************************************************************************** */
/* pss_calc() from the 4 transfert options choose the best one                */
/* ************************************************************************** */
t_cost	pss_calc(t_cost c);

#endif
