NAME				= push_swap

LIBFT				= ./libft/libft.a
PRINTF				= ./ft_printf/libftprintf.a
CC					= cc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SRCS			= main.c \
				  errors.c \
				  setup_a.c \
				  setup_b.c \
				  split_args.c \
				  stack_build.c \
				  stack_prep.c \
				  stack_utils.c \
				  op_push.c \
				  op_swap.c \
				  op_rotate.c \
				  op_rev_rotate.c \
				  sort_full.c \
				  sort_small.c

OBJ					= $(SRCS:.c=.o)

all: 				$(NAME)

$(LIBFT):
					@make -C ./libft

$(PRINTF):
					@make -C ./ft_printf

$(NAME): 			$(OBJ) $(LIBFT) $(PRINTF)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o:				%.c push_swap.h
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJ)
					@make clean -C ./libft
					@make clean -C ./ft_printf

fclean: 			clean
					$(RM) $(NAME)
					$(RM) $(LIBFT)
					$(RM) $(PRINTF)

re: 				fclean all

.PHONY: 			all clean fclean re