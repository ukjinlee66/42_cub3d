/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:25:00 by youlee            #+#    #+#             */
/*   Updated: 2020/08/03 21:33:22 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_substr(char *s, int start, int len)
{
	char		*res;
	int			strsize;
	int			idx;

	idx = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	strsize = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[idx] && idx < len)
	{
		res[idx] = s[start + idx];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
