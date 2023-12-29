# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 14:59:58 by luicasad          #+#    #+#              #
#    Updated: 2023/12/28 20:53:28 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Here, rR is equivalent to --no-builtin-rules --no-builtin-variables.
MAKEFLAGS += rR
#$(foreach x,$(filter-out .% MAKE% SHELL CURDIR,$(.VARIABLES)) MAKEINFO,$(if $(filter default,$(origin $x)),$(eval override undefine $x)))
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED			=	\033[0;91m
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
SRCDIR_PUSHS		= ./src/pushs/
SRCDIR_CHECK		= ./src/check/
SRCDIR_PRINT		= ./src/ftpri/
SRCDIR_LIBFT		= ./src/libft/
SRCDIR_STACK		= ./src/stack/
SRCDIR_ARGPA		= ./src/argpa/	

OBJDIR 			= ./obj/
INCDIR 			= ./inc/
LIBDIR			= ./lib/
REQUIRED_DIRS	= $(OBJDIR) $(INCDIR) $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 			= gcc
WRNFL			= -Wall -Wextra -Werror
DBGFL			= -g
CFLGS			= $(DBGFL) $(WRNFL) -c
HEADS			= -I$(INCDIR)
#LFLGS 			= -Wl,-v
LFLGS 			= 

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #
NAMELIBPRINTF 		= libftprintf.a
PATH_PRINT 		= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
LOADLIBPRINTF 		= ftprintf

NAMELIBFT 		= libft.a
PATH_LIBFT 		= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 		= ft

NAMELIBPSS 		= libpss.a
PATH_STACK 		= $(addprefix $(SRCDIR_STACK), $(NAMELIBPSS))
LOADLIBSS 		= pss

NAMELIBARGPA 		= libargpar.a
PATH_ARGPA 		= $(addprefix $(SRCDIR_ARGPA), $(NAMELIBARGPA))
LOADLIBARGPA 		= argpar

MYLIBS			= $(NAMELIBPRINTF) $(NAMELIBFT) $(NAMELIBPSS) $(NAMELIBARGPA)
LLIBS 			= -L$(LIBDIR) -l$(LOADLIBPRINTF) -l$(LOADLIBFT) -l$(LOADLIBSS) -l$(LOADLIBARGPA)
# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #


SRCS_PUSHS = max_min.c \
		push_swap.c

SRCS_CHECK = chk_init.c \
		chk_trea.c \
		chk_swap.c \
		chk_psoo.c \
		chk_rota.c \
		chk_rrot.c \
		checker.c

FILE_PUSHS = $(addprefix $(SRCDIR_PUSHS), $(SRCS_PUSHS))
FILE_CHECK = $(addprefix $(SRCDIR_CHECK), $(SRCS_CHECK))

OBJS_PUSHS = $(addprefix $(OBJDIR), $(SRCS_PUSHS:.c=.o))
OBJS_CHECK = $(addprefix $(OBJDIR), $(SRCS_CHECK:.c=.o))

$(info source files $(SRCS_PUSHS))
$(info source paths $(FILE_PUSHS))
$(info object patha $(OBJS_PUSHS))
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
makelibs: $(MYLIBS) 

$(NAMELIBPRINTF): makelibftprintf 
$(NAMELIBFT): 	  makelibft
$(NAMELIBPSS):    makelibpss
$(NAMELIBARGPA):  makelibargpa

makelibft:
	$(MAKE) -C $(SRCDIR_LIBFT)

makelibftprintf:
	$(MAKE) -C $(SRCDIR_PRINT)

makelibpss:
	$(MAKE) -C $(SRCDIR_STACK)

makelibargpa:
	$(MAKE) -C $(SRCDIR_ARGPA)

# .......................... targets construction ............................ #
$(NAME): Makefile $(OBJS_PUSHS)
	@echo "$(GREEN)========== GATHERING PUSH_SWAP OBJECTS =============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_PUSHS) -o $@ $(LLIBS)

$(BONUS): Makefile $(OBJS_CHECK)
	@echo "$(MAGENTA)========== GATHERING CHECKER OBJECTS ===============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_CHECK) -o $@ $(LLIBS)
# .......................... objects construction ............................ #
# ################   PUSH_SWAP
#$(OBJS_PUSHS): $(FILE_PUSHS)
#	@echo "========== COMPILING PUSH_SWAP FILES ==============="
#	$(CC) $(CFLGS) $? -o $@ $(HEADS)  

# ################   CHECKER
#$(OBJS_CHECK): $(FILE_CHECK)
#	@echo "========== COMPILING CHECK FILES ==================="
#	$(CC) $(CFLGS) $< -o $@ $(HEADS)  
   
#$(OBJS_PUSHS): $(FILE_PUSHS) 
#	@echo "========== COMPILING PUSH_SWAP FILES ==============="
#	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_PUSHS)%.c
	@echo "$(GREEN)========== COMPILING PUSH_SWAP FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_CHECK)%.c
	@echo "$(MAGENTA)========== COMPILING  CHECKER  FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS) 
 
.PHONY: clean
clean:
	@echo "========== Cleaning Push_swap objects =============="
	rm -f $(OBJS_PUSHS)
	@echo "========== Cleaning prinf_f objects ================"
	$(MAKE) -C $(SRCDIR_PRINT)  clean
	@echo "========== Cleaning libft  objects ================="
	$(MAKE) -C $(SRCDIR_LIBFT)  clean
	@echo "========== Cleaning libft  objects ================="
	$(MAKE) -C $(SRCDIR_STACK)  clean
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
	$(MAKE) -C $(SRCDIR_PRINT)  norma
	$(MAKE) -C $(SRCDIR_LIBFT)  clean
	$(MAKE) -C $(SRCDIR_STACK)  clean
	norminette $(SRCDIR_PUSHS) $(SRCDIR_CHECK)
bonusrun:
	valgrind --tool=memcheck --leak-check=yes ./$(BONUS)
bonusrung:
	valgrind --tool=massif --stacks=yes ./$(BONUS)
