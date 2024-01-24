# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 12:57:35 by luicasad          #+#    #+#              #
#    Updated: 2024/01/24 15:33:47 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 	test_pss
INCDIR	=	../../../inc/
LIBDIR	=	../../../lib/
LIBPSS	=	libpss.a
LIBPRI	=	libftprintf.a

CC		=	cc
CFLAGS	=	-g -Werror -Wextra -Wall
HEADS	=	-I$(INCDIR)
LIBS	=	-L$(LIBDIR) -l:$(LIBPSS) -l:$(LIBPRI)
SRCS	=	test_pss.c

OBJS	=	test_pss.o

all: Makefile $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)
	rm -f $(OBJS)

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
