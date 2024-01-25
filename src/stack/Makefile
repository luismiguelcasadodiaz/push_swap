# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 18:16:38 by luicasad          #+#    #+#              #
#    Updated: 2024/01/25 10:16:16 by luicasad         ###   ########.fr        #
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
NAME		= libpss.a
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
#OBJDIR		= ../../obj/
INCDIR		= ../../inc/
LIBDIR		= ../../lib/
OBJDIR		=  
vpath %.a $(LIBDIR)
#LIBDIR		=
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC			=	cc
CFLAGS		=	-g -Wall -Wextra  -Werror
HEADS		=	-I$(INCDIR)
# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.

# ============================================================================ #
#                                   SOURCES                                    #
# ============================================================================ #
HEADER	=	libpss.h
SRCS	=	nod_init.c \
		nod_free.c \
		pss_init.c \
		pss_size.c \
		pss_prin.c \
		pss_prnu.c \
		pss_empt.c \
		pss_isor.c \
		pss_isori.c \
		pss_reve.c \
		pss_push.c \
		pss_pope.c \
		pss_mami.c \
		pss_have.c \
		pss_maxi.c \
		pss_mini.c \
		pss_imax.c \
		pss_imin.c \
		pss_sman.c \
		pss_bign.c \
		pss_free.c \
		pss_peek.c \
		pss_peek_idx.c \
		pss_unpe.c \
		pss_ovbo.c \
		pss_bott.c \
		pss_swap.c \
		pss_swsw.c \
		pss_psoo.c \
		pss_rota.c \
		pss_roro.c \
		pss_rrot.c \
		pss_rrrr.c \
		pss_nrot.c \
		pss_nrro.c \
		pss_mkid.c \
		pss_pall.c \
		pss_prad.c \
		pss_deep.c \
		pss_nmtp.c \
		pss_extr.c \
		pss_inse.c \
		pss_chea.c



# Generate a list of object files by replacing .c with .o 
_OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(_OBJS))

# The default goal is the first target of the first rule in the first makefile.
# This is the reason for writtting this rule the first one


all: $(NAME)
#	$(info sources $(SRCS))
#	$(info objects $(_OBJS))
#	$(info targets $(OBJS))

#includes all dependencies files.
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
include $(SRCS:.c=.d)

# Vous devez utiliser la commande ar pour créer votre bibliothèque
# NOTE rcs:
# - r  means that if the library already exists, replace the old files within the library with your new files. 
# - c means create the library if it did not exist. 
# - s can be seen to mean 'sort' (create a sorted index of) the library, so that it will be indexed and faster to access the functions in the library.
#   Therefore, rcs can be seen to mean replace, create, sort

$(NAME): $(OBJS) 
	@echo "$(RED)LIBPSS ========== GATHERING ALL OBJECTS ====================$(DEF_COLOR)"
	ar rcs $(LIBDIR)$(NAME) $?


# For each c file create its object file.
# $(OBJS): $(SRCS) Makefile $(INCDIR)$(HEADER)

%.o: %.c Makefile
	@echo "$(RED)LIBPSS ========== COMPILING ALL OBJECTS ====================$(DEF_COLOR)"
	$(CC) $(CFLAGS)  -c $< -o $@ $(HEADS)

#for each c file create its dependency file
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# removes all generated object files
clean:
	@echo "$(RED)LIBPSS ========== REMOVING ALL OBJECTS =====================$(DEF_COLOR)"
	rm -f $(OBJS)
	rm -f *.d

# removes target file and all generated object files
fclean: clean
	@echo "$(RED)LIBPSS ========== REMOVING TARGET ==========================$(DEF_COLOR)"
	rm -f $(LIBDIR)$(NAME)

# rebuild all after removing all
re: fclean all
	@echo "$(RED)LIBPSS ================ REBUILDING =========================$(DEF_COLOR)"


norma:
	@echo "$(RED)LIBPSS ============== CHECKING NORME =======================$(DEF_COLOR)"
	norminette $(SRCS)

.PHONY: all clean fclean re

