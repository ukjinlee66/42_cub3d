/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 20:12:00 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 03:10:36 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void			init_config(t_config *config)
{
	int				i;

	config->req_width = 848;
	config->req_height = 480;
	i = 0;
	while (i < TEXTURES)
		config->tex_path[i++] = NULL;
	config->c[TEX_NORTH] = 0xFFFFFF;
	config->c[TEX_SOUTH] = 0xCCCCCC;
	config->c[TEX_WEST] = 0xFF44FF;
	config->c[TEX_EAST] = 0x44FF44;
	config->c[TEX_SKY] = 0x33C6E3;
	config->c[TEX_FLOOR] = 0xA0764C;
	config->map = NULL;
	config->row = 0;
	config->col = 0;
	config->save_arg = 0;
	config->rotate_speed = .05;
	config->fov = .66;
	i = 0;
	while (i < C_LAST)
		config->set[i++] = 0;
}

int				clear_config(t_config *config)
{
	int				i;

	i = 0;
	while (i < TEXTURES)
	{
		if (config->tex_path[i])
			free(config->tex_path[i]);
		config->tex_path[i] = NULL;
		i++;
	}
	if (config->map)
		free(config->map);
	config->map = NULL;
	return (0);
}
