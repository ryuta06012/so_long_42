#include "so_long.h"

int	to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	check_so_long_extension(char *str, char *ext)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
		exit (1);
	}
	while (str[i + j] && ext[j])
	{
		if (to_upper(str[i + j]) == to_upper(ext[j]))
			j++;
		else
			break ;
	}
	if (ext[j] == '\0' && str[i + j] == '\0')
		return (0);
	ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
	exit (1);
}
