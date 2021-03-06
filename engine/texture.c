/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:13:53 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 18:47:30 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		row_check(t_texture *tex, int row)
{
	int				i;
	t_pos			tex_pos;

	i = 0;
	tex_pos.y = row;
	while (i < tex->width)
	{
		tex_pos.x = i;
		if (cal_color2(tex, &tex_pos) != 0x0)
			return (0);
		i++;
	}
	return (1);
}

static int		col_check(t_texture *tex, int col)
{
	int				i;
	t_pos			tex_pos;

	i = 0;
	tex_pos.x = col;
	while (i < tex->height)
	{
		tex_pos.y = i;
		if (cal_color2(tex, &tex_pos) != 0x0)
			return (0);
		i++;
	}
	return (1);
}

static int		loading(t_cub *cub, char *path, int i)
{
	if (!path)
		return (1);
	cub->texture[i].tex = mlx_xpm_file_to_image(cub->window.ptr, path,
			&cub->texture[i].width, &cub->texture[i].height);
	cub->texture[i].ptr = (int*)mlx_get_data_addr(cub->texture[i].tex,
			&cub->texture[i].bpp, &cub->texture[i].size_l,
			&cub->texture[i].endian);
	return (0);
}

void			load_texture(t_cub *cub)
{
	int				i;
	int				j;

	i = 0;
	while (i < 17)
	{
		if (loading(cub, cub->texture[i].path, i))
			return ;
		j = 0;
		while (j < cub->texture[i].height && col_check(&cub->texture[i], j))
			j++;
		cub->texture[i].start.x = j;
		while (j < cub->texture[i].height && !col_check(&cub->texture[i], j))
			j++;
		cub->texture[i].end.x = j;
		j = 0;
		while (j < cub->texture[i].height && row_check(&cub->texture[i], j))
			j++;
		cub->texture[i].start.y = j;
		while (j < cub->texture[i].height && !row_check(&cub->texture[i], j))
			j++;
		cub->texture[i].end.y = j;
		i++;
	}
}
