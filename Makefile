# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/07/21 20:24:27 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

SRC := 	main.c \
		mlx_handle/hook_handle.c \
		engine/camera.c \
		engine/check_coin_in_map.c \
		engine/color.c \
		engine/cross_hair.c \
		engine/draw.c \
		engine/image.c \
		engine/life_bar.c \
		engine/position.c \
		engine/raycast.c \
		engine/sky_floor.c \
		engine/sprite.c \
		engine/sprite2.c \
		engine/sprite_sort.c \
		engine/table.c \
		engine/texture.c \
		engine/window.c \
		function/MAX.c \
		function/ft_memcpy.c \
		function/vector_cross_product.c

OBJ := $(SRC:.c=.o)

HEADERS = -I SDL/SDL2.framework/Headers/ -I SDL/SDL2_mixer.framework/Headers/ \
		  -I.

LIBS = -lmlx -framework OpenGl -framework Appkit -rpath \
	   @loader_path/SDL -framework SDL2 -F SDL/ -framework SDL2_mixer\
	   -F SDL/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(HEADERS) $(LIBS) $(OBJ) -o cub3D
	@echo "Done"

%.o : %.c
		$(CC) -c $(HEADERS) $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all
