/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:44:18 by youlee            #+#    #+#             */
/*   Updated: 2020/06/21 17:02:18 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_str
{
	char			*content;
	struct s_str	*next;
}					t_str;

int					ft_strlen(char const *str);

int					ft_strcmp(char *str1, char *str2);
#endif
