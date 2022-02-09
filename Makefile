NAME = fdf1

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

HEADER = ./incs

SRC = srcs/ft_hextoi.c  srcs/gnl.c srcs/read_file.c get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c srcs/errors.c  srcs/ft_init.c srcs/main.c  srcs/draw.c srcs/draw_tools.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS	= -Wall -Wextra -Werror
FRAMEWORKS =  -lmlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0m"
	@make bonus -C libft/
	@$(CC) -o $(NAME)  $(SRC) libft/libft.a  $(FRAMEWORKS)  -g
	@echo "\033[1;5;1;36m";
	@echo "$(_RED)+------------------------+";
	@echo "|  $(_GREEN)______ _____  ______  $(_RED)|";
	@echo "| $(_GREEN)|  ____|  __/|  ____| $(_RED)|";
	@echo "| $(_GREEN)| |__  | |  | | |__    $(_RED)|";
	@echo "| $(_GREEN)|  __| | |  | |  __|   $(_RED)|";
	@echo "| $(_GREEN)| |    | |__| | |      $(_RED)|";
	@echo "| $(_GREEN)|_|    |_____/|_|      $(_RED)|";
	@echo "|                        |";
	@echo "+---------------$(_WHITE_WHITE)mmasstou$(_WHITE)-+";
	@echo "\033[0m"

clean:
	@rm -f $(OBJ)
	make  clean -C libft/

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY	:				all clean fclean re