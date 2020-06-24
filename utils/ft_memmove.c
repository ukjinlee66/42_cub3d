/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:42:46 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 17:44:41 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			*ft_memmove(void *dest, const void *src, unsigned long num)
{
	unsigned char			*de;
	const unsigned char		*sr;
	unsigned long			idx;

	idx = 0;
	if (!dest && !src)
		return (dest);
	de = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (sr < de)
		while (num-- > 0)
			de[num] = sr[num];
	else
		while (idx < num)
		{
			de[idx] = sr[idx];
			idx++;
		}
	return (dest);
}
