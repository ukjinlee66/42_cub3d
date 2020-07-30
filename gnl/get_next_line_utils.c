/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 00:14:20 by youlee            #+#    #+#             */
/*   Updated: 2020/07/31 00:18:16 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strchr(char *src, char c)
{
	int				idx;

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

char			*ft_strdup(char *str)
{
	char			*res;
	int				i;

	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_strjoin(const char *s1, const char *s2)
{
	char			*res;
	int				idx;
	int				idx2;
	int				len;

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

int				ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strncpy(char *dest, char *src, int num)
{
	int				i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
