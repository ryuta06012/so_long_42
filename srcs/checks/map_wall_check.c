#include "so_long.h"

bool	map_wall_check_width(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (info->map[0][j] != '\0')
	{
		if (info->map[0][j] == '1')
			j++;
		else
			return (false);
	}
	j = 0;
	i = info->height - 1;
	while (info->map[i][j] != '\0')
	{
		if (info->map[i][j] == '1')
			j++;
		else
			return (false);
	}
	return (true);
}

bool	map_wall_check_height(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != NULL)
	{
		if (info->map[i][0] == '1')
			i++;
		else
			return (false);
	}
	i = 0;
	j = info->width - 1;
	while (info->map[i] != NULL)
	{
		if (info->map[i][j] == '1')
			i++;
		else
			return (false);
	}
	return (true);
}

void	map_wall_check(t_info *info)
{
	if (!map_wall_check_width(info) || !map_wall_check_height(info))
	{
		free_array(info->map);
		ft_putstr_fd("Error.\nThe map must be closed/surrounded by walls.\n", 2);
		exit(1);
	}
}
