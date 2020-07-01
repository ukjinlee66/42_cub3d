/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:14:00 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 05:25:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>
int					load_tex(t_tex *tex, t_window *win, char *path)
{
	if (path)
	{
		tex->path = path;
		if ((tex->tex = mlx_xpm_file_to_image(win->ptr, path,
						&tex->width, &tex->height)))
		{
			tex->ptr = mlx_get_data_addr(tex->tex, &tex->bpp,
					&tex->size_l, &tex->endian);
		}
		else
			return (0);
	}
	return (1);
}

void				clear_tex(t_game *game)
{
	int			i;

	i = 0;
	while (i < TEXTURES)
	{
		if (game->tex[i].tex)
			mlx_destroy_image(game->window.ptr, game->tex[i].tex);
		game->tex[i].tex = NULL;
		game->tex[i].ptr = NULL;
		i++;
	}
}

static int			col_check(t_tex *tex, int col)
{
	int			i;
	t_pos		pos;

	pos.x = col;
	i = 0;
	while (i < tex->height)
	{
		pos.y = i;
		if (get_tex_color(tex, &pos) != 0x0)
			return (0);
		i++;
	}
	return (1);
}

static int			row_check(t_tex *tex, int row)
{
	int			j;
	t_pos		pos;

	pos.y = row;
	j = 0;
	while (j < tex->width)
	{
		pos.x = j;
		if (get_tex_color(tex, &pos) != 0x0)
			return (0);
		j++;
	}
	return (1);
}

int					load_textures(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < TEXTURES)
	{
		if (!load_tex(&game->tex[i], &game->window, game->config.tex_path[i]))
			return (0);
		j = 0;
		while (j < game->tex[i].height && col_check(game->tex, j))
			j++;
		game->tex[i].start.x = j;
		printf("game->tex[i].start.x",
		while (j < game->tex[i].height && !col_check(game->tex, j))
			j++;
		game->tex[i].end.x = j;
		j = 0;
		while (j < game->tex[i].width && row_check(game->tex, j))
			j++;
		game->tex[i].start.y = j;
		while (j < game->tex[i].width && !row_check(game->tex, j))
			j++;
		game->tex[i].end.y = j;
		i++;
	}
	return (0);
}
