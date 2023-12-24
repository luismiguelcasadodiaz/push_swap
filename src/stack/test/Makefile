# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 12:57:35 by luicasad          #+#    #+#              #
#    Updated: 2023/12/24 10:48:31 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 	test_pss
INCDIR	=	../../../inc/
LIBDIR	=	../../../lib/
LIBPSS	=	libpss.a
LIBPRI	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall
HEADS	=	-I$(INCDIR)
LIBS	=	-L$(LIBDIR) -l:$(LIBPSS) -l:$(LIBPRI)
SRCS	=	test_pss.c

OBJS	=	test_pss.o

all: Makefile $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADS) 

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
