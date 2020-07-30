/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:33:29 by youlee            #+#    #+#             */
/*   Updated: 2020/07/30 17:35:23 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strchr(char *src, char c)
{
	int			idx;

	idx = 0;
	while (src[idx])
	{
		if (src[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
