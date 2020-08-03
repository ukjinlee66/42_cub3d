/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:37:33 by youlee            #+#    #+#             */
/*   Updated: 2020/08/03 17:47:33 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			set_resolution(t_cub *cub, char *line)
{
	int			i;
	int			j;
	int			num;
	char		**str;

	i = 0;
	j = 0;
	while (line[++i])
		if (line[i] != ' ' && line[i] < '0' && line[i] > '9')
			return ;
	i = 0;
	str = ft_split(line, ' ');
	while (str[i] != 0)
		i++;
	if (i != 3)
		return ;
	cub->req_col = ft_atoi(str[1]);
	cub->req_row = ft_atoi(str[2]);
	exit_game(cub);
}
