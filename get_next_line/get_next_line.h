/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:34:04 by youlee            #+#    #+#             */
/*   Updated: 2020/06/25 20:44:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup2(char *str, int ch, char **str2, char *temp);
int			ft_strchr(char *str, char c, char **buf2, int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen2(char *str, char ***buf2, int cc, int row);
char		*ft_strncpy(char *dest, char *src, unsigned int n);

#endif
