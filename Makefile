# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 14:59:58 by luicasad          #+#    #+#              #
#    Updated: 2023/12/23 10:37:27 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Here, rR is equivalent to --no-builtin-rules --no-builtin-variables.
#MAKEFLAGS += rR
#$(foreach x,$(filter-out .% MAKE% SHELL CURDIR,$(.VARIABLES)) MAKEINFO,$(if $(filter default,$(origin $x)),$(eval override undefine $x)))
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #

NAME 			= push_swap
BONUS 			= checker
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
SRCDIR_PUSHS	= ./src/pushs/
SRCDIR_CHECK	= ./src/check/
SRCDIR_PRINT	= ./src/ftpri/
SRCDIR_LIBFT	= ./src/libft/
SRCDIR_STACK	= ./src/stack/

OBJDIR 			= ./obj/
INCDIR 			= ./inc/
LIBDIR			= ./lib/
REQUIRED_DIRS	= $(OBJDIR) $(INCDIR) $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= gcc
WRNFL			= -Wall -Wextra -Werror
DBGFL			= -g
CFLGS			= $(DBGFL) $(WRNFL) -c
HEADS			= -I$(INCDIR)
LFLGS 			= -Wl,-v

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #
NAMELIBPRINTF 	= libftprintf.a
PATH_PRINT 		= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
LOADLIBPRINTF 	= ftprintf

$(info name $(NAMELIBPRINTF))
$(info dir  $(SRCDIR_PRINT))
$(info path $(PATH_PRINT))
$(info link $(LOADLIBPRINTF))

NAMELIBFT 		= libft.a
PATH_LIBFT 		= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 		= ft

$(info name $(NAMELIBFT))
$(info dir  $(SRCDIR_LIBFT))
$(info path $(PATH_LIBFT))
$(info link $(LOADLIBFT))

LIBS 			= -L$(LIBDIR) -l$(LOADLIBPRINTF) -l$(LOADLIBFT) 
# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

#SRCS_STACK = nod_type.c 

SRCS_PUSHS = push_swap.c \
				max_min.c

SRCS_CHECK = checker.c

FILE_STACK = $(addprefix $(SRCDIR_STACK), $(SRCS_STACK))
FILE_PUSHS = $(addprefix $(SRCDIR_PUSHS), $(SRCS_PUSHS))
FILE_CHECK = $(addprefix $(SRCDIR_CHECK), $(SRCS_CHECK))

OBJS_STACK = $(addprefix $(OBJDIR), $(SRCS_STACK:.c=.o))
OBJS_PUSHS = $(addprefix $(OBJDIR), $(SRCS_PUSHS:.c=.o))
OBJS_CHECK = $(addprefix $(OBJDIR), $(SRCS_CHECK:.c=.o))


# ============================================================================ #
#                                 RULES                                        #
# ============================================================================ #
all: makedirs makelibs $(NAME)
bonus: makedirs makelibs $(BONUS)
# .......................... directories creation ............................ #

makedirs:
	$(shell for d in $(REQUIRED_DIRS); \
 				do \
 					[[ -d $$d ]] || mkdir -p $$d; \
 				done)

# .......................... library construction ............................ #
makelibs: makelibft makelibftprintf

makelibft:
	$(MAKE) -C $(SRCDIR_LIBFT)

makelibftprintf:
	$(MAKE) -C $(SRCDIR_PRINT)


# .......................... objects construction ............................ #
# ################   STACK
$(OBJS_STACK): $(FILE_STACK) Makefile 
	@echo "========== COMPILING STACK FILES ==================="
	$(CC) $(CFLGS) -c $< -o $@ $(HEADS) 

# ################   PUSH_SWAP
$(OBJS_PUSHS): $(FILE_PUSHS) Makefile 
	@echo "========== COMPILING PUSH_SWAP FILES ==============="
	$(CC) $(CFLGS) -c $< -o $@ $(HEADS)  

# ################   CHECKER
$(OBJS_CHECK): $(FILE_CHECK) Makefile 
	@echo "========== COMPILING CHECK FILES ==================="
	$(CC) $(CFLGS) -c $< -o $@ $(HEADS) 
   
# .......................... targets construction ............................ #
$(NAME): Makefile $(OBJS_STACK) $(OBJS_PUSHS)
	@echo "========== GATHERING PUSH_SWAP OBJECTS ============="
	$(CC) $(LFLGS) $(OBJS_STACK) $(OBJS_PUSHS) -o $@ $(LIBS)

$(BONUS): Makefile $(OBJS_STACK) $(OBJS_CHECK)
	@echo "========== GATHERING CHECKER OBJECTS ==============="
	$(CC) $(LFLGS) $(OBJS_STACK) $(OBJS_CHECK) -o $@ $(LIBS)

.PHONY: clean
clean:
	@echo "========== Cleaning Push_swap objects =============="
	rm -f $(OBJS_PUSHS)
	@echo "========== Cleaning stack objects =================="
	rm -f $(OBJS_STACK)
	@echo "========== Cleaning prinf_f objects ================"
	$(MAKE) -C $(SRCDIR_PRINT)  clean
	@echo "========== Cleaning libft  objects ================="
	$(MAKE) -C $(SRCDIR_LIBFT)  clean
	@echo "========== Cleaning libraries *.a =================="
	rm -f $(LIBDIR)*

.PHONY: fclean
fclean : clean
	@echo "========== Cleaning executable Push_Swap ==========="
	rm -f $(NAME)
	@echo "======= Cleaning prinf_f objects and library ======="
	$(MAKE) -C $(SRCDIR_PRINT)  fclean
	@echo "======= Cleaning libft   objectsand library ========"
	$(MAKE) -C $(SRCDIR_LIBFT)  fclean

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
