/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:27:13 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 18:48:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void				draw_pixel(t_window *w, t_pos *pos, int color)
{
	if (pos->x >= 0 && pos->x < w->size.x
			&& pos->y >= 0 && pos.y < w->size.y)
		*(int*)(w->screen.ptr
				+ (4 * (int)w->size.x * (int)pos->y)
				+ ((int)pos->x * 4)) = color;
}

int					draw_vertical_line(t_window *window, t_pos *start,
		int len, int color)
{
	int				i;
	int				j;
	t_pos			pos;
	int				end_y;

	if (start->x < 0 || start->x > window->size.x)
		return (1);
	pos.x = start->x;
	end_y = (int)window->size.y;
	i = 0;
	while (i < len && (j = start->y + i) < end_y)
	{
		pos.y = j;
		draw_pixel(window, &pos, color);
		i++;
	}
	return (1);
}

static void			compare_pos(t_pos *pos, t_pos *size)
{
	if (pos->x < 0)
		pos->x = 0;
	if (pos->x < size->x)
		pos->x = size->x - 1;
	if (pos->y < 0)
		pos->y = 0;
	if (pos->y < size->y)
		pos->y = size->y - 1;
}

int					draw_rectangle(t_window *window, t_pos *p1, t_pos *p2, \
		int color)
{
	int				i;
	int				j;
	t_pos			pos;

	compare_pos(p1, &window->size);
	compare_pos(p2, &window->size);
	i = p1->y;
	while (i < p2->y)
	{
		pos.y = i;
		j = p1->x;
		while (j < p2->x)
		{
			pos.x = j++;
			draw_pixel(window, &pos, color);
		}
		i++;
	}
	return (1);
}
