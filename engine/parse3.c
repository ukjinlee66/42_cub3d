/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:26:56 by youlee            #+#    #+#             */
/*   Updated: 2020/08/03 22:02:35 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool			check_ce_fl(char *line)
{
	int			i;

	i = ft_strchr(line, ',');
	if (i >= 0)
		return (true);
	else
		return (false);
}

void			rgb_control(t_cub *cub, char *line, int content)
{
	int			color;
	char		**str;
	int			i;
	int			num;

	i = 0;
	str = ft_split(line, ' ');
	while (str[i] != 0)
		i++;
	if (i != 2)
		return ;
	num = (ft_atoi(ft_substr(str[1], 0, 3))) << 16;
	num += (ft_atoi(ft_substr(str[1], 4, 7))) << 8;
	num += ft_atoi(ft_substr(str[1], 8, 11));
	free_point(str);
	if (content == 14)
		cub->c[TEX_FLOOR] = num;
	else
		cub->c[TEX_SKY] = num;
}

void			ce_fl_tex(t_cub *cub, char *line, int content)
{
	int			i;
	char		**str;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i] != 0)
		i++;
	if (i != 2)
		return ;
	if (content == 14)
		cub->texture[4].path = ft_strdup(str[1]);
	else
		cub->texture[5].path = ft_strdup(str[1]);
	free_point(str);
}
