/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:44:18 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 18:12:17 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/*
 ** struct
*/

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

/*
 ** function
*/

int					ft_strlen(char const *str);

int					ft_strcmp(char *str1, char *str2);

int					ft_endwith(char const *str, char const *end);

int					ft_in_set(char c, char const *set);

char				*ft_itoa(int n);

void				*ft_memmove(void *dest, const void *src, unsigned long num);

char				**ft_split(char const *s, char c);

char				*ft_strdup(char const *s);

char				*ft_substr(char const *s, int start, int len);

void				set_pos(t_pos *pos, double x, double y);

void				copy_pos(t_pos *pos, t_pos *pos2);
#endif
