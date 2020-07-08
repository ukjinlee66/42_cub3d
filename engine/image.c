/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:35:59 by youlee            #+#    #+#             */
/*   Updated: 2020/07/06 16:25:42 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_img(t_window *window, t_image *img)
{
	img->img = mlx_new_image(window->ptr, window->size.x, window->size.y);
	img->ptr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
}
