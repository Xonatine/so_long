NAME = so_long
SOURCE = ./src/so_long.c \
			./src/get_next_line_utils.c \
			./src/get_next_line.c \
			./src/read_map.c \
			./src/check_map.c \
			./src/construct_map.c \
			./src/flood_fill.c \
			./src/free_memo.c \
			./src/game.c \
			./src/window.c \
			./src/player.c

OBJS = $(SOURCE:.c=.o)

LDFLAGS = -L lib/libft -l ft
LIBMLX	= ./lib/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS = --no-print-directory

all:$(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME) -fsanitize=address -g3

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -fsanitize=address -g3

clean:
	@$(MAKE) clean -C ./lib/libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
#.SILENT: