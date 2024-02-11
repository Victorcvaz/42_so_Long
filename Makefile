NAME	:= so_long
CC		:= gcc
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./MLX42

HEADERS	:= -I ./src/mandatory/so_long.h -I $(LIBMLX)/include/MLX42/
LIB 	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm ./libft/libft.a
SRCS	:= $(addprefix ./src/mandatory/, so_long.c checks.c exit_game.c load_game.c actions.c init_data.c)
OBJS	:= $(SRCS:.c=.o)

all: libft/libft.a $(LIBMLX)/build/libmlx42.a $(NAME)

libft/libft.a:
	@echo "Compiling libft..."
	@make -sC ./libft

$(LIBMLX)/build/libmlx42.a:
	@echo "Compiling MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo "Linking complete!"

clean:
	@rm -f $(OBJS)
	@echo "Cleanup complete!"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX)/build
	@make -sC ./libft fclean
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re
