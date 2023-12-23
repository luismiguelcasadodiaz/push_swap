# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 18:08:17 by luicasad          #+#    #+#              #
#    Updated: 2023/12/23 10:25:05 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += rR
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW	=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #
NAME = libftprintf.a
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
#OBJDIR		= ../../obj/
#INCDIR		= ../../inc/
LIBDIR		= ../../lib/
OBJDIR		= 
INCDIR		= ../../inc/
#LIBDIR		= 
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
HEADS		=	-I$(INCDIR)
# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.

SRCS := ft_write_str.c \
        ft_write_c.c \
		ft_write_int_base.c \
		ft_write_uns_base.c \
		ft_write_ptr.c \
		ft_write_int.c \
		ft_write_dec.c \
		ft_write_uns.c \
		ft_write_hex_low.c \
		ft_write_hex_cap.c \
		ft_printf.c

# Generate a list of object files by replacing .c with .o

_OBJS:=$(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(_OBJS))
 
# The default goal is the first target of the first rule in the first makefile.
# This is the reason for writtting this rule the first one

all: $(NAME)


$(NAME): $(OBJS)
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======= GATHERING ALL OBJECTS ====================="
	ar rcs $(LIBDIR)$(NAME) $?


# For each c file create its object file.

#$(OBJS): $(SRCS)
%.o: %.c Makefile
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======= COMPILING ALL OBJECTS ====================="
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADS)


# removes all generated object files
clean:
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======= REMOVING ALL OBJECTS ======================"
	rm -f $(OBJS)

# removes target file and all generated object files
fclean: clean
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======= REMOVING TARGET =========================="
	rm -f $(LIBDIR)$(NAME)

# rebuild all after removing all
re: fclean all
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======== REBUILDING ==============================="
norma: $(SRCS)
	@echo "$(ORANGE)FT_PRINTF$(DEF_COLOR)======= CHECKING NORME ==========================="
	norminette  $(SRCS)


.PHONY: all clean fclean re

