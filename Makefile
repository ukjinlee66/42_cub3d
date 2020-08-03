# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/08/03 21:33:53 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC := 	main.c \
		mlx_handle/hook_handle.c \
		engine/camera.c \
		engine/check_coin_in_map.c \
		engine/color.c \
		engine/cross_hair.c \
		engine/draw.c \
		engine/image.c \
		engine/icon.c \
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
		engine/music2.c \
		function/print_get.c \
		function/max.c \
		function/ft_memcpy.c \
		function/vector_cross_product.c \
		function/ft_strcmp.c \
		function/ft_strdup.c \
		function/ft_strjoin.c \
		function/ft_strlen.c \
		function/ft_strncpy.c \
		function/ft_strchr.c \
		function/ft_split.c \
		function/ft_atoi.c \
		function/free_pt.c \
		function/ft_substr.c \
		engine/jump_func.c \
		engine/door.c \
		engine/parse.c \
		engine/parse2.c \
		engine/parse3.c \
		bitmap.c \
		gnl/get_next_line.c \
		reset.c

OBJ := $(SRC:.c=.o)

HEADERS = -I SDL/SDL2.framework/Headers/ -I SDL/SDL2_mixer.framework/Headers/ \
		  -I minilibx_opengl/ -I minilibx_mms/ -I gnl/ -I.

LIBS = libmlx.a libmlx.dylib -framework OpenGL -framework Appkit -rpath \
	   @loader_path/SDL -framework SDL2 -F SDL/ -framework SDL2_mixer\
	   -F SDL/

all: $(NAME)

$(NAME): $(OBJ)
	@cd minilibx_mms; cp -r libmlx.dylib ../
	@cd minilibx_opengl; cp -r libmlx.a ../
	@$(CC) $(CFLAG) $(HEADERS) $(LIBS) $(OBJ) -o cub3D
	@echo "Done"

%.o : %.c
		$(CC) -c $(HEADERS) $< -o $@

clean:
	@rm -rf libmlx.dylib
	@rm -rf libmlx.a
	@rm -rf cub3D.bmp
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all
