/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:37:13 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 17:45:38 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void			init_idx(int *idx)
{
	int			index;

	index = 0;
	while (index < 3)
		idx[index++] = 0;
}

char				**ft_split(char const *s, char c)
{
	char		**res;
	int			idx[3];

	init_idx(idx);
	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * 4096)))
		return (NULL);
	while (s[idx[0]] != 0)
	{
		if (s[idx[0]] != c)
		{
			if (!(res[idx[1]] = (char*)malloc(sizeof(char) * 4096)))
				return (NULL);
			idx[2] = 0;
			while ((s[idx[0]] != c) && s[idx[0]])
				res[idx[1]][idx[2]++] = s[idx[0]++];
			res[idx[1]++][idx[2]] = '\0';
		}
		else
			idx[0]++;
	}
	res[idx[1]] = 0;
	return (res);
}
