# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 08:49:17 by mmasstou          #+#    #+#              #
#    Updated: 2022/02/24 11:00:36 by mmasstou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf1
LIBFT_NAME = libft/libft.a

define HEADER_m                          
     _,---.                   _,---.  
  .-`.' ,  \  _,..---._    .-`.' ,  \ 
 /==/_  _.-'/==/,   -  \  /==/_  _.-' 
/==/-  '..-.|==|   _   _\/==/-  '..-. 
|==|_ ,    /|==|  .=.   ||==|_ ,    / 
|==|   .--' |==|,|   | -||==|   .--'  
|==|-  |    |==|  '='   /|==|-  |     
/==/   \    |==|-,   _`/ /==/   \     
`--`---'    `-.`.____.'  `--`---'  
endef
export HEADER_m

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

SRC = srcs/ft_hextoi.c  srcs/gnl.c srcs/read_file.c get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c srcs/errors.c  srcs/ft_init.c   srcs/ft_padding.c srcs/window_resolution.c srcs/ft_colors.c srcs/ft_zoom.c srcs/altitude.c srcs/draw_tools.c srcs/fdf_free.c srcs/close_button.c
OBJ = $(SRC:.c=.o)

SRC_MANDATORY = srcs/fdf.c srcs/draw.c 
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)



SRC_BONUS = srcs/fdf_bonus.c srcs/ft_translate.c  srcs/ft_rotation.c  srcs/menu.c   srcs/events_function.c  srcs/draw_bonus.c srcs/draw_tools_bonus.c srcs/events_function_utils.c srcs/menu_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS	= -Wall -Wextra -Werror
FRAMEWORKS =  -lmlx -framework AppKit -framework OpenGL

all: $(NAME)


$(NAME): $(OBJ) $(OBJ_MANDATORY)
	@make  bonus -C libft/
	@$(CC) -o $(NAME)  $(OBJ) $(OBJ_MANDATORY) $(LIBFT_NAME)   $(FRAMEWORKS)  -g
	@echo "+- fdf $(_BLUE)[done]$(_END)-+";
	@echo "\033[0m"
	@echo "$(_BLUE) $${HEADER_m} $(_END)";
	@echo "\033[1;5;1;36m";
	@echo "+-$(_BLUE)mmasstou Ooo-Mandatory-ooO-+$(_END)";
	@echo "\033[0m"
	
%.o:%.c ./incs/fdf.h Makefile
	@${CC} ${CFLAGS} -I . -o $@ -c $<
		
bonus : $(OBJ) $(OBJ_BONUS)
	@make bonus -C libft/
	@$(CC) -o $(NAME)  $(SRC) $(SRC_BONUS) $(LIBFT_NAME) $(FRAMEWORKS)  -g
	@echo "+- fdf $(_GREEN)[done]$(_END)-+";
	@echo "\033[0m"
	@echo "$(_GREEN) $${HEADER_m}$(_END)";
	@echo "\033[1;5;1;36m";
	@echo "+-$(_GREEN)mmasstou Ooo-Bonus-ooO-+ $(_END)";
	@echo "\033[0m"

clean:
	@rm -f $(OBJ) $(OBJ_MANDATORY) $(OBJ_BONUS)
	@make  clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@echo "+- clean $(NAME) \x1b[34m[done]\x1b[0m-+";
	@make fclean -C libft/

re: fclean all

.PHONY	:	all clean fclean re bonus
