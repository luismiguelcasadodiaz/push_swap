# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 14:59:58 by luicasad          #+#    #+#              #
#    Updated: 2023/12/21 19:12:28 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #

NAME 			= push_swap
BONUS 			= checker
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
SRCDIR_PUSHS = ./src/pushs/
SRCDIR_CHECK = ./src/check/
SRCDIR_PRINT = ./src/ftpri/
SRCDIR_LIBFT = ./src/libft/
SRCDIR_STACK = ./src/stack/

OBJDIR = ./obj/
INCDIR = ./inc/

# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= gcc
WRNFL			= -Wall -Wextra -Werror
DBGFL			= -g
CFLGS			= $(DBGFL) $(WRNFL) -c

CREATELIB = ar vrs
LFLGS = -Wl,-v

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #
NAMELIBPRINTF 	= libftprintf.a
PATH_PRINT 		= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
LOADLIBPRINTF 	= ftprintf
INCL_PRINT 		= $(addprefix $(INCDIR), $(NAMELIBPRINTF))

$(info $(NAMELIBPRINTF))
$(info $(SRCDIR_PRINT))
$(info $(PATH_PRINT))
$(info $(LOADLIBPRINTF))
$(info $(INCL_PRINT))
$(info $(PATH_PRINT))
$(info $(INCDIR))

NAMELIBFT 		= libft.a
PATH_LIBFT 		= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 		= ft
INCL_LIBFT 		= $(addprefix $(INCDIR), $(NAMELIBFT))

LIBS 			= -L$(INCDIR) -l$(LOADLIBPRINTF) -l$(LOADLIBFT) 
$(info $(NAMELIBFT))
$(info $(SRCDIR_LIBFT))
$(info $(PATH_LIBFT))
$(info $(LOADLIBFT))
$(info $(INCL_LIBFT))
$(info $(PATH_LIBFT))
$(info $(INCDIR))
# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

SRCS_PRINT = ft_write_str.c \
        ft_write_c.c \
		ft_write_int_base.c \
		ft_write_int.c \
		ft_write_dec.c \
		ft_write_uns.c \
		ft_write_hex_low.c \
		ft_write_hex_cap.c \
		ft_printf.c

SRCS_LIBFT = ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_tolower.c \
       ft_toupper.c \
	   ft_atoi.c \
       ft_strtrim.c \
       ft_strncmp.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_strnstr.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_split.c \
       ft_itoa.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_strmapi.c \
       ft_striteri.c \
	   ft_lstnew_bonus.c \
	   ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c \
	   ft_lstmap_bonus.c \
	   ft_lstadd_back_bonus.c \
	   ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c
SRCS_STACK = nod_type.c 

SRCS_PUSHS = push_swap.c \
			max_min.c

SRCS_CHECK = checker.c

FILE_PRINT = $(addprefix $(SRCDIR_PRINT), $(SRCS_PRINT))
FILE_LIBFT = $(addprefix $(SRCDIR_LIBFT), $(SRCS_LIBFT))
FILE_STACK = $(addprefix $(SRCDIR_STACK), $(SRCS_STACK))
FILE_PUSHS = $(addprefix $(SRCDIR_PUSHS), $(SRCS_PUSHS))
FILE_CHECK = $(addprefix $(SRCDIR_CHECK), $(SRCS_CHECK))

OBJS_PRINT = $(addprefix $(OBJDIR), $(SRCS_PRINT:.c=.o))
OBJS_LIBFT = $(addprefix $(OBJDIR), $(SRCS_LIBFT:.c=.o))
OBJS_STACK = $(addprefix $(OBJDIR), $(SRCS_STACK:.c=.o))
OBJS_PUSHS = $(addprefix $(OBJDIR), $(SRCS_PUSHS:.c=.o))
OBJS_CHECK = $(addprefix $(OBJDIR), $(SRCS_CHECK:.c=.o))


all: $(NAME)
bonus: $(BONUS)

$(NAME): Makefile $(NAMELIBPRINTF) $(NAMELIBFT) $(OBJS_STACK) $(OBJS_PUSHS)
	@echo "========== GATHERING PUSH_SWAP OBJECTS ============="
	$(CC) $(LDFLAGS) $(OBJS_STACK) $(OBJS_PUSHS) -o $@ $(LIBS)

$(BONUS): Makefile $(NAMELIBPRINTF) $(NAMELIBFT) $(OBJS_STACK) $(OBJS_CHECK)
	@echo "========== GATHERING CHECKER OBJECTS ==============="
	$(CC) $(LDFLAGS) $(OBJS_STACK) $(OBJS_CHECK) -o $@ $(LIBS)


# ################   LIBFT
$(NAMELIBFT):
	@echo "========== COMPILING LIBFT FILES ==================="
	mkdir -p $(OBJDIR)
	cd $(SRCDIR_LIBFT) && $(MAKE)
	@echo "========== COPYING libft.a to ./inc ================"
	mv $(PATH_LIBFT) $(INCDIR)

# ################   LIBPRINTF
$(NAMELIBPRINTF):
	@echo "========= GATHERING FT_PRINTF  OBJECTS ============="
	mkdir -p $(OBJDIR)
	cd $(SRCDIR_PRINT) && $(MAKE)
	mv $(PATH_PRINT) $(INCDIR)

# ################   STACK
$(OBJS_STACK): $(FILE_STACK) Makefile $(SRCDIR_STACK)/ps_stack.h
	@echo "========== COMPILING STACK FILES ==================="
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

# ################   PUSH_SWAP
$(OBJS_PUSHS): $(FILE_PUSHS) Makefile $(SRCDIR_PUSHS)/push_swap.h 
	@echo "========== COMPILING PUSH_SWAP FILES ==============="
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

# ################   CHECKER
$(OBJS_CHECK): $(FILE_CHECK) Makefile 
	@echo "========== COMPILING CHECK FILES ==================="
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	@echo "========== Cleaning Push_swap objects =============="
	rm -f $(OBJS_PUSHS)
	@echo "========== Cleaning stack objects =================="
	rm -f $(OBJS_STACK)
	@echo "========== Cleaning prinf_f objects ================"
	cd $(SRCDIR_PRINT) && $(MAKE) clean
	@echo "========== Cleaning libft  objects ================="
	cd $(SRCDIR_LIBFT) && $(MAKE) clean
	@echo "========== Cleaning libraries *.a =================="
	rm -f $(INCDIR)*

.PHONY: fclean
fclean : clean
	@echo "========== Cleaning executable Push_Swap ==========="
	rm -f $(NAME)

.PHONY: re
re: fclean all
	@echo "========== Rebuilding Push_swap ===================="

.PHONY: bonus_clean
bonus_clean:
	@echo "========== Cleaning CHECKER objects ================"
	rm -f $(OBJS_CHECK)

.PHONY: bonus_fclean
bonus_fclean: bonus_clean
	@echo "========== Cleaning executable Checker ============="
	rm -f $(BONUS)
norma:
	norminette $(SRCDIR_STACK) $(SRCDIR_PUSHS) $(SRCDIR_CHECK)
