#include "../includes/so_long_bonus.h"

bool	second_enemy_encount_x_dir(t_info *info)
{
	if (info->e2_direction != RIGHT \
	&& (info->map[info->mem.e2_y][info->mem.e2_x - 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x - 1] == 'P'))
	{
		info->e2_direction = LEFT;
		info->mem.e2_x -= 1;
		return (true);
	}
	if (info->e2_direction != LEFT \
	&& (info->map[info->mem.e2_y][info->mem.e2_x + 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x + 1] == 'P'))
	{
		info->e2_direction = RIGHT;
		info->mem.e2_x += 1;
		return (true);
	}
	return (false);
}

bool	second_enemy_encount_x(t_info *info)
{
	if (info->mem.e2_y <= info->y \
	&& (info->map[info->mem.e2_y + 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y + 1][info->mem.e2_x] == 'P'))
	{
		info->mem.e2_y += 1;
		return (true);
	}
	else if (info->mem.e2_y >= info->y \
	&& (info->map[info->mem.e2_y - 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y - 1][info->mem.e2_x] == 'P'))
	{
		info->mem.e2_y -= 1;
		return (true);
	}
	if (second_enemy_encount_x_dir(info))
		return (true);
	return (false);
}

bool	second_enemy_encount_y_dir(t_info *info)
{
	if (info->e2_direction != BACK \
	&& (info->map[info->mem.e2_y + 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y + 1][info->mem.e2_x] == 'P'))
	{
		info->e2_direction = FRONT;
		info->mem.e2_y += 1;
		return (true);
	}
	if (info->e2_direction != FRONT \
	&& (info->map[info->mem.e2_y - 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y - 1][info->mem.e2_x] == 'P'))
	{
		info->e2_direction = BACK;
		info->mem.e2_y -= 1;
		return (true);
	}
	return (false);
}

bool	second_enemy_encount_y(t_info *info)
{
	if (info->mem.e2_x < info->x \
	&& (info->map[info->mem.e2_y][info->mem.e2_x + 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x + 1] == 'P'))
	{
		info->e2_direction = RIGHT;
		info->mem.e2_x += 1;
		return (true);
	}
	else if (info->mem.e2_x > info->x \
	&& (info->map[info->mem.e2_y][info->mem.e2_x - 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x - 1] == 'P'))
	{
		info->e2_direction = LEFT;
		info->mem.e2_x -= 1;
		return (true);
	}
	if (second_enemy_encount_y_dir(info))
		return (true);
	return (false);
}

void	second_enemy_encounter(t_info *info, int *cnt)
{
	if (*cnt == 200)
	{
		if (info->mem.e2_x == info->x || info->mem.e2_x == info->mem.f_x)
		{
			if (second_enemy_encount_x(info))
				return ;
		}
		else if (info->mem.e2_y == info->y || info->mem.e2_y == info->mem.f_y)
		{
			if (second_enemy_encount_y(info))
				return ;
		}
		if (second_enemy_encount_else(info))
			return ;
	}
	if ((info->mem.e2_x == info->x && info->mem.e2_y == info->y) \
	|| (info->mem.e2_x == info->mem.f_x && info->mem.e2_y == info->mem.f_y))
		close_window(info);
}
