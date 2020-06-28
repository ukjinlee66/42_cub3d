# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 22:30:38 by youlee            #+#    #+#              #
#    Updated: 2020/06/28 19:53:08 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -I ./ *.c config/*.c engine/*.c utils/*.c get_next_line/*.c -D BUFFER_SIZE=1 -lmlx -framework OpenGL -framework -Appkit
	./a.out
