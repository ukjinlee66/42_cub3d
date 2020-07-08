/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:03:47 by youlee            #+#    #+#             */
/*   Updated: 2020/07/04 12:04:30 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			set_position(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void			copy_position(t_pos *pos1, t_pos *pos2)
{
	pos1->x = pos2->x;
	pos1->y = pos2->y;
}
