# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 12:37:46 by jluknar-          #+#    #+#              #
#    Updated: 2020/03/04 19:44:11 by jluknar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = srcs/main.c minilibx/libmlx.a srcs/cub3d.a
FLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework Appkit
all: 
	make -C srcs/
	make -C minilibx/
	gcc $(FLAGS) $(SRC) -o $(NAME)
	rm -f srcs/cub3d.a
	rm -f minilibx/libmlx.a
	
clean:

	make clean -C srcs/
	make clean -C minilibx/

fclean: clean
	make fclean -C srcs/
	make clean -C minilibx/
	rm -f $(NAME)

re: fclean all