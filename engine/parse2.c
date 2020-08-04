/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:37:33 by youlee            #+#    #+#             */
/*   Updated: 2020/08/04 17:00:53 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				set_ce_fl(t_cub *cub, char *line, int content)
{
	bool		type;

	type = check_ce_fl(line);
	if (type)
		rgb_control(cub, line, content);
	else
		ce_fl_tex(cub, line, content);
	return (0);
}

int				set_dsprite(t_cub *cub, char *line, int content)
{
	char		**str;

	str = ft_split(line, ' ');
	cub->texture[content].path = ft_strdup(str[1]);
	free_point(str);
	return (1);
}

int				set_content(t_cub *cub, char *line, int content)
{
	char		**str;
	int			i;
	int			handle;

	//1 ~ 12
	handle = (content < 5) ? -1 : 1;
	i = 0;
	str = ft_split(line, ' ');
	while (str[i] != 0)
		i++;
	if (i != 2)
		return (0);
	cub->texture[content + handle].path = ft_strdup(str[1]);
	free_point(str);
	return (1);
}

int				set_resolution(t_cub *cub, char *line)
{
	int			i;
	int			j;
	int			num;
	char		**str;

	i = 0;
	j = 0;
	while (line[++i])
		if (line[i] != ' ' && line[i] < '0' && line[i] > '9')
			return (0);
	i = 0;
	str = ft_split(line, ' ');
	while (str[i] != 0)
		i++;
	if (i != 3)
		return (0);
	cub->window.size.y = (double)ft_atoi(str[1]);
	cub->window.size.x = (double)ft_atoi(str[2]);
	free_point(str);
	return (1);
}
