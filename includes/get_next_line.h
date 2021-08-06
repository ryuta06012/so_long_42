#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/uio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

int		new_line_return(char *mem);
int		get_next_line(const int fd, char **line);
size_t	gnl_strlen(const char *str);
size_t	new_line_strlen(const char *line);
char	*gnl_strjoin(char *s1, char const *s2);

#endif