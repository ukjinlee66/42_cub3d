/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:15:01 by youlee            #+#    #+#             */
/*   Updated: 2020/07/30 18:37:49 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "he.h"

char			*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	i = 0;
	if ((res = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
