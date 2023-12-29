# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 12:57:35 by luicasad          #+#    #+#              #
#    Updated: 2023/12/29 08:20:50 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 	test_argpa
INCDIR	=	../../../inc/
LIBDIR	=	../../../lib
LIBPSS	=	libpss.a
LIBPRI	=	libftprintf.a
LIBARG	=	libargpar.a
LIBFT	=	libft.a

CC		=	cc
CFLAGS	=	-g -Werror -Wextra -Wall
HEADS	=	-I$(INCDIR)
LIBS	=	-L$(LIBDIR) -l:$(LIBARG) -l:$(LIBPSS) -l:$(LIBPRI)  -l:$(LIBFT)
SRCS	=	test_argpa.c

OBJS	=	test_argpa.o

all: Makefile $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADS) 
re: fclean all
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
run:
	valgrind --tool=memcheck --leak-check=yes ./$(NAME)
rung:
	valgrind --tool=massif --stacks=yes ./$(NAME)
