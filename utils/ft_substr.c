/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:34:07 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 17:36:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char			*ft_substr(char const *s, int start, int len)
{
	char			*ans;
	int				idx;
	int				s_size;
	int				len2;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len2 = len;
	s_size = ft_strlen(s);
	idx = 0;
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[idx] && idx < len2)
	{
		ans[idx] = s[start + idx];
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
