#include "get_next_line.h"

size_t	new_line_strlen(const char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	new_line_return(char *mem)
{
	int	i;

	i = 0;
	if (!mem)
		return (0);
	while (mem[i] != '\0')
	{
		if (mem[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	str = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[j] != '\0')
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	return (str);
}
