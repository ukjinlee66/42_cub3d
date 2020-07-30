#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(char *str);
int			ft_strchr(char *str, char c);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strlen(const char *str);
char		*ft_strncpy(char *dest, char *src, int num);

#endif