# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/07/14 14:41:19 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -I. *.c engine/*.c function/*.c mlx_handle/*.c -lmlx -framework OpenGL -framework Appkit
	./a.out
