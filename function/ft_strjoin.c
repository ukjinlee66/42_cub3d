/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:21:37 by youlee            #+#    #+#             */
/*   Updated: 2020/07/31 00:13:21 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		idx;
	int		idx2;
	int		len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	idx = 0;
	idx2 = 0;
	if (!(res = malloc(sizeof(char) + len)))
		return (NULL);
	while (s1[idx])
	{
		res[idx] = s1[idx];
		idx++;
	}
	while (s2[idx2])
		res[idx++] = s2[idx2++];
	res[idx] = 0;
	return (res);
}
