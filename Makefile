NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAMELIBPRINTF = libprintf.a
NAMELIBFT = libft.a

SRCDIR_PUSHS = ./src/pushs/
SRCDIR_CHECK = ./src/checker/
SRCDIR_PRINT = ./src/ft_printf/
SRCDIR_LIBFT = ./src/libft/
SRCDIR_STACK = ./src/stack/

OBJDIR = ./obj/
INCDIR = ./inc/

#LIBS = -L$(INCDIR) -lft -lprintf 
LIBS = -Linc  -lft -lprintf 

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

SRCS_STACK = nod_type.c \

SRCS_PUSHS = push_swap.c

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

INCL_LIBFT = $(addprefix $(INCDIR), $(NAMELIBFT))
INCL_PRINT = $(addprefix $(INCDIR), $(NAMELIBPRINTF))

$(info $(FILE_PRINT))
$(info $(OBJS_PRINT))

all: $(NAME)
bonus: $(BONUS)

$(NAME): Makefile $(NAMELIBPRINTF) $(NAMELIBFT) $(OBJS_STACK) $(OBJS_PUSHS)
	@echo "========== GATHERING PUSH_SWAP OBJECTS ============="
	$(CC) $(OBJS_STACK) $(OBJS_PUSHS) -o $@ $(LIBS)

$(BONUS) : Makefile $(OBJS_PRINT) $(OBJS_LIBFT) $(OBJS_STACK) $(OBJS_CHECK)
	@echo "========== GATHERING CHECKER OBJECTS ==============="
	$(CC) $(OBJS_STACK) $(OBJS_CHECK) -o $@ $(LIBS)


# ################   LIBFT
$(NAMELIBFT) : $(OBJS_LIBFT)
	@echo "========= GATHERING LIBFT OBJECTS =================="
	ar rcs $(INCL_LIBFT) $?

$(OBJS_LIBFT): $(FILE_LIBFT) Makefile $(SRCDIR_LIBFT)/libft.h
	@echo "========== COMPILING LIBFT FILES ==================="
	$(CC) $(CFLAGS) -c $< -o $@ 

# ################   LIBPRINTF
$(NAMELIBPRINTF) : $(OBJS_PRINT)
	@echo "========= GATHERING LIBFT OBJECTS =================="
	ar rcs $(INCL_PRINT) $?
$(OBJS_PRINT): $(FILE_PRINT) Makefile $(SRCDIR_PRINT)/ft_printf.h
	@echo "========== COMPILING FT_PRINTF FILES ==============="
	$(CC) $(CFLAGS) -c $< -o $@ 


$(OBJS_STACK): $(FILE_STACK) Makefile $(SRCDIR_STACK)/ps_stack.h
	@echo "========== COMPILING STACK FILES ==================="
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS_PUSHS): $(FILE_PUSHS) Makefile 
	@echo "========== COMPILING PUSH_SWAP FILES ==============="
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS_CHECK): $(FILE_CHECK) Makefile 
	@echo "========== COMPILING PUSH_SWAP FILES ==============="
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	@echo "========== Cleaning Push_swap objects =============="
	rm -f $(OBJS_PUSHS)
	@echo "========== Cleaning stack objects =================="
	rm -f $(OBJS_STACK)
	@echo "========== Cleaning prinf_f objects ================"
	rm -f $(OBJS_PRINT)
	@echo "========== Cleaning libft  objects ================="
	rm -f $(OBJS_LIBFT)
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

