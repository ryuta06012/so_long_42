#include "so_long.h"

bool	enemy_disposition(t_info *info)
{
	if (info->height > 100 && info->width > 100)
		return (true);
	return (false);
}

void	first_enemy_position(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == '0')
			{
				info->e_space = 1;
				info->mem.e_x = j;
				info->mem.e_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	second_enemy_position(t_info *info)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = info->map;
	i = info->height - 1;
	while (i > -1)
	{
		j = info->width - 1;
		while (j > -1)
		{
			if (tmp[i][j] == '0')
			{
				info->e_space = 1;
				info->mem.e2_x = j;
				info->mem.e2_y = i;
				return ;
			}
			j--;
		}
		i--;
	}
}

void	enemy_position(t_info *info)
{
	if (enemy_disposition(info))
	{
		first_enemy_position(info);
		second_enemy_position(info);
	}
}

void	player_feed_position(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->mem.feed_count = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'P')
			{
				info->x = j;
				info->y = i;
			}
			if (info->map[i][j] == 'C')
				info->mem.feed_count += 1;
			j++;
		}
		i++;
	}
}
