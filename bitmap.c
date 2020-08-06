/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:39:23 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 19:16:53 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		int_to_char(int value, unsigned char *start)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static void		bmp_header(t_cub *cub, int fd, int filesize)
{
	int						i;
	unsigned char			data[54];

	i = -1;
	while (++i < 54)
		data[i] = 0;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	int_to_char(filesize, data + 2);
	data[10] = (unsigned char)(54);
	data[14] = (unsigned char)(40);
	int_to_char((int)cub->window.size.x, data + 18);
	int_to_char((int)cub->window.size.y, data + 22);
	data[26] = (unsigned char)(1);
	data[28] = (unsigned char)(24);
	write(fd, data, 54);
}

static int		get_pixel(t_window *w, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(w->screen.ptr
			+ (4 * (int)w->size.x * ((int)w->size.y - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static void		bmp_pixels(t_cub *cub, int fd, int pad)
{
	unsigned char	zero[3];
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < cub->window.size.y)
	{
		j = 0;
		while (j < cub->window.size.x)
		{
			color = get_pixel(&cub->window, j, i);
			write(fd, &color, 3);
			write(fd, &zero, pad);
			j++;
		}
		i++;
	}
}

int				screenshot(t_cub *cub)
{
	int			fd;
	int			filesize;
	int			pad;

	put_screen(cub);
	put_img(cub);
	mlx_string_put(cub->window.ptr, cub->window.win,
			cub->window.half.x - 50,
			cub->window.size.y - 50, 0xFF0000, cub->coin);
	pad = (4 - ((int)cub->window.size.x * 3) % 4) % 4;
	filesize = 54 + (3 * (cub->window.size.x + pad) * cub->window.size.y);
	if ((fd = open("cub3D.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0777)) < 0)
		return (0);
	bmp_header(cub, fd, filesize);
	bmp_pixels(cub, fd, pad);
	close(fd);
	return (1);
}
