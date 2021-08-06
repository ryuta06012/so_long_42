#include "../includes/get_next_line_bonus.h"

static char	*get_save_line(char *mem)
{
	int		i;
	int		j;
	char	*gl;

	i = 0;
	if (!mem)
		return (NULL);
	i = new_line_strlen(mem);
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	gl = (char *)malloc(sizeof(char) * ((gnl_strlen(mem) - i) + 1));
	if (!gl)
		return (NULL);
	i++;
	j = 0;
	while (mem[i] != '\0')
		gl[j++] = mem[i++];
	gl[j] = '\0';
	free(mem);
	return (gl);
}

static char	*get_line(char *mem)
{
	int		i;
	char	*gl;

	i = 0;
	if (!mem)
		return (0);
	i = new_line_strlen(mem);
	gl = (char *)malloc(sizeof(char) * (i + 1));
	if (!gl)
		return (0);
	i = 0;
	while (mem[i] != '\0' && mem[i] != '\n')
	{
		gl[i] = mem[i];
		i++;
	}
	gl[i] = '\0';
	return (gl);
}

static	char	*line_get(char *mem, int fd, int *read_value)
{
	char	*buff;

	*read_value = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!new_line_return(mem) && *read_value != 0)
	{
		*read_value = read(fd, buff, BUFFER_SIZE);
		if (*read_value == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[*read_value] = '\0';
		mem = gnl_strjoin(mem, buff);
	}
	free(buff);
	return (mem);
}

int	get_next_line(int fd, char **line)
{	
	static char	*mem;
	int			*read_value;
	int			i;

	i = 1;
	read_value = &i;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	mem = line_get(mem, fd, read_value);
	if (mem == NULL)
		return (-1);
	*line = get_line(mem);
	mem = get_save_line(mem);
	if (i == 0)
		return (0);
	return (1);
}
