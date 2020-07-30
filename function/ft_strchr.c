/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:33:29 by youlee            #+#    #+#             */
/*   Updated: 2020/07/31 00:12:53 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strchr(char *src, char c)
{
	int			idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		if (src[idx] == c)
			return (idx);
		idx++;
	}
	if (src[idx] == c)
		return (idx);
	return (-1);
}
