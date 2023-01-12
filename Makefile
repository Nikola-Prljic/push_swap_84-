NAME	= push_swap
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRC		= main.c add_to_stack.c argv_to_stack.c stack_rotate.c stack_swap.c sort_small.c sort_actions.c sort.c meridian.c destroy_list.c sort_big.c extract_number.c sort_big_ulties.c
OBJ		= $(SRC:.c=.o)
CC		= @cc

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ft_printf_libft
			@$(CC) $(CFLAGS) $(OBJ) ft_printf_libft/libftprintf.a -o $(NAME)
			@echo // push_swap compiled! //

clean:
			@$(RM) $(OBJ)
			@make clean -C ft_printf_libft
			@echo // objekt files removed //

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C ft_printf_libft
			@echo // all files removed //

re:			fclean all
			@echo // Clenad and rebuild everything! //

.PHONY:		all clean fclean re