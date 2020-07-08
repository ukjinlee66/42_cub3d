/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:33:37 by youlee            #+#    #+#             */
/*   Updated: 2020/07/04 11:34:11 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (!dest && !src)
		return (NULL);
	while (n != 0)
	{
		*(de++) = *(sr++);
		n--;
	}
	return (dest);
}
