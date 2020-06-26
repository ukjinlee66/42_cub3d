/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:11:59 by youlee            #+#    #+#             */
/*   Updated: 2020/06/26 16:30:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdbool.h>
# include "get_next_line/get_next_line.h"
# include "utils/utils.h"
# include <fcntl.h>

/*
** direction
*/

# define C_R			0
# define C_NO			1
# define C_SO			2
# define C_WE			3
# define C_EA			4
# define C_S			5
# define C_SU			6
# define C_SC			7
# define C_FT			8
# define C_ST			9
# define C_F			10
# define C_C			11
# define C_MAP			12
# define C_LAST			13

# define TEXTURES		9
# define TEX_NORTH		0
# define TEX_SOUTH		1
# define TEX_WEST		2
# define EAST			3
# define TEX_SKY		4
# define TEX_FLOOR		5
# define TEX_SPRITE		6
# define TEX_SPRITE_UP	7
# define TEX_SPRITE_C	8

typedef struct			s_config
{
	int					req_height;
	int					req_width;
	int					*map;
	int					row;
	int					col;
	int					save_arg;
	double				rotate_speed;
	double				move_speed;
	char				*tex_path[TEXTURES];
	unsigned			c[TEXTURES];
	int					set[C_LAST];
	double				fov;
}						t_config;

/*
 * function
*/

int						FINT(double x);
int						CHECK_BOT(t_pos p, t_config c);
int						CHECK_TOP(t_pos p);
int						IN_MAP(t_pos p, t_config c);
int						*MAP(t_pos p, t_config c);
int						*MAP_XY(double x, double y, t_config c);

#endif
