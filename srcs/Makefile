LIB = ar rcs
RM = rm -f

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

NAME = cub3d.a

SRC = parse_textures_and_res.c read_map_data.c read_map_file.c \
      get_next_line.c events.c movement.c raycasting.c collisions.c \
	  textures.c read_sprites.c raycasting2.c raycasting3.c raycasting4.c\
	  map_checks.c save_bmp.c init.c utils.c read_map_data2.c \
	  

OBJ = $(SRC:.c=.o)

INCLUDE = cub3d.h get_next_line.h ../ft_printf/ft_printf.h

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME):
	make -C ../ft_printf/
	cp ../ft_printf/libftprintf.a ./$(NAME)
	gcc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	make fclean -C ../ft_printf/
	make clean

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean