/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:32:10 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 17:33:25 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int				ft_endwith(char const *str, char const *end)
{
	int			len;
	int			end_len;

	len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > len)
		return (0);
	return (!ft_strcmp(str + len - end_len, end));
}
