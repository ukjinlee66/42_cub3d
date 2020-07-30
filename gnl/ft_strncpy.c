/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:30:01 by youlee            #+#    #+#             */
/*   Updated: 2020/07/30 18:28:21 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "he.h"

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
