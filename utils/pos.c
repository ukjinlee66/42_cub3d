/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:26:40 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 17:27:37 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void			copy_pos(t_pos *pos, t_pos *pos2)
{
	pos->x = pos2->x;
	pos->y = pos2->y;
}
