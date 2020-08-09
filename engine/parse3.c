/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:26:56 by youlee            #+#    #+#             */
/*   Updated: 2020/08/09 18:45:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_number(char *str, int divide)
{
	int			ret;

	ret = (ft_atoi(ft_substr(&str[1], 0, 3)));
	ret = ret < 0 ? 0 : ret;
	ret = ret > 255 ? 255 : ret;
	return (ret << divide);
}

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
	num = check_number(*str, 16);
	num += check_number(*str, 8);
	num += check_number(*str, 0);
	/*num = (ft_atoi(ft_substr(str[1], 0, 3))) << 16;
	num += (ft_atoi(ft_substr(str[1], 4, 7))) << 8;
	num += ft_atoi(ft_substr(str[1], 8, 11));
	*/free_point(str);
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
