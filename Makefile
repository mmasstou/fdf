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

SRC = srcs/ft_hextoi.c  srcs/gnl.c srcs/read_file.c get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c srcs/errors.c  srcs/ft_init.c  srcs/draw.c srcs/draw_tools.c
OBJ = $(SRC:.c=.o)

SRC_MANDATORY = srcs/fdf.c
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)



SRC_BONUS = srcs/fdf_bonus.c srcs/ft_translate.c srcs/ft_scroll.c srcs/ft_rotation.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS	= -Wall -Wextra -Werror
FRAMEWORKS =  -lmlx -framework AppKit -framework OpenGL

all: $(NAME)


$(NAME): $(OBJ) $(OBJ_MANDATORY)
	@make  bonus -C libft/
	@$(CC) -o $(NAME)  $(OBJ) $(OBJ_MANDATORY) libft/libft.a  $(FRAMEWORKS)  -g
	@echo "\033[1;5;1;36m";
	@echo "+-$(_WHITE_WHITE)mmasstou$(_WHITE)------MANDATORY-+";
	@echo "\033[0m"
	
bonus : $(OBJ) $(OBJ_BONUS)
	@make bonus -C libft/
	@$(CC) -o $(NAME)  $(OBJ) $(OBJ_BONUS) libft/libft.a  $(FRAMEWORKS)  -g
	@echo "\033[0m"
	@echo "\033[1;5;1;36m";
	@echo "+-$(_WHITE_WHITE)mmasstou$(_WHITE)--------BONUS-+";
	@echo "\033[0m"

clean:
	@rm -f $(OBJ) $(OBJ_MANDATORY) $(OBJ_BONUS)
	@make  clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY	:				all clean fclean re bonus