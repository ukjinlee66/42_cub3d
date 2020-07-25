# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/07/21 21:30:49 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

# CFLAG = -Wall -Wextra -Werror

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
		engine/music.c \
		function/print_get.c \
		function/MAX.c \
		function/ft_memcpy.c \
		function/vector_cross_product.c

OBJ := $(SRC:.c=.o)

HEADERS = -I SDL/SDL2.framework/Headers/ -I SDL/SDL2_mixer.framework/Headers/ \
		  -I minilibx_opengl/ -I.

LIBS = libmlx.a libmlx.dylib -framework OpenGL -framework Appkit -rpath \
	   @loader_path/SDL -framework SDL2 -F SDL/ -framework SDL2_mixer\
	   -F SDL/

all: $(NAME)

$(NAME): $(OBJ)
	@cd minilibx_mms; cp -r libmlx.dylib ../
	@cd minilibx_opengl; cp -r libmlx.a ../
	@$(CC) $(HEADERS) $(LIBS) $(OBJ) -o cub3D
	@echo "Done"

%.o : %.c
		$(CC) -c $(HEADERS) $< -o $@

clean:
	@rm -rf libmlx.dylib
	@rm -rf libmlx.a
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all
