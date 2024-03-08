NAME = push_swap
SRCS = arg_control.c error_utils.c push_swap.c swap_push_utils.c rotate_utils.c \
		sort_utils.c sort_handlers.c over_utils.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@make -C ./libft -s
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[33m                 _                                 "
	@echo "\033[33m _ __  _   _ ___| |__      _____      ____ _ _ __  "
	@echo "\033[33m| '_ \| | | / __| '_ \    / __\ \ /\ / / _\` | '_ \ "
	@echo "\033[34m| |_) | |_| \__ \ | | |   \__ \\ V  V / (_| | |_) |"
	@echo "\033[34m| .__/ \__,_|___/_| |_|___|___/ \_/\_/ \__,_| .__/ "
	@echo "\033[34m|_|                  |_____|                |_|    "
	@echo "Program is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft clean -s
	@rm -rf $(OBJS)
	@echo "Object files removed!"

fclean: clean
	@make -C ./libft fclean -s
	@rm -rf $(NAME)
	@echo "Program is removed!"

re: fclean all

.PHONY: all clean fclean re
