#include "../includes/so_long_bonus.h"

void	free_line(void *line)
{
	free(line);
	line = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
