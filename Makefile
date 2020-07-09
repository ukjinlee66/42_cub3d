# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/07/08 17:12:34 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -I. *.c engine/*.c function/*.c mlx_handle/*.c minilibx_opengl/libmlx.a -framework OpenGL -framework Appkit
	./a.out
