#include "so_long.h"

bool	enemy_encount_x_dir(t_info *info)
{
	if (info->e_direction != RIGHT \
	&& (info->map[info->mem.e_y][info->mem.e_x - 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x - 1] == 'P'))
	{
		info->e_direction = LEFT;
		info->mem.e_x -= 1;
		return (true);
	}
	if (info->e_direction != LEFT \
	&& (info->map[info->mem.e_y][info->mem.e_x + 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x + 1] == 'P'))
	{
		info->e_direction = RIGHT;
		info->mem.e_x += 1;
		return (true);
	}
	return (false);
}

bool	enemy_encount_x(t_info *info)
{
	if (info->mem.e_y <= info->y \
	&& (info->map[info->mem.e_y + 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y + 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = FRONT;
		info->mem.e_y += 1;
		return (true);
	}
	else if (info->mem.e_y >= info->y \
	&& (info->map[info->mem.e_y - 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y - 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = BACK;
		info->mem.e_y -= 1;
		return (true);
	}
	if (enemy_encount_x_dir(info))
		return (true);
	return (false);
}

bool	enemy_encount_y_dir(t_info *info)
{
	if (info->e_direction != FRONT \
	&& (info->map[info->mem.e_y - 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y - 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = BACK;
		info->mem.e_y -= 1;
		return (true);
	}
	if (info->e_direction != BACK \
	&& (info->map[info->mem.e_y + 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y + 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = FRONT;
		info->mem.e_y += 1;
		return (true);
	}
	return (false);
}

bool	enemy_encount_y(t_info *info)
{
	if (info->mem.e_x < info->x \
	&& (info->map[info->mem.e_y][info->mem.e_x + 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x + 1] == 'P'))
	{
		info->e2_direction = RIGHT;
		info->mem.e_x += 1;
		return (true);
	}
	else if (info->mem.e_x > info->x \
	&& (info->map[info->mem.e_y][info->mem.e_x - 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x - 1] == 'P'))
	{
		info->e2_direction = LEFT;
		info->mem.e_x -= 1;
		return (true);
	}
	if (enemy_encount_y_dir(info))
		return (true);
	return (false);
}

/* 
・playerがいる方向に移動
・障害物があった場合、避けて移動する
*/
void	enemy_encounter(t_info *info, int *cnt)
{
	if (*cnt == 200)
	{
		if (info->mem.e_x == info->x || info->mem.e_x == info->mem.f_x)
		{
			if (enemy_encount_x(info))
				return ;
		}
		else if (info->mem.e_y == info->y || info->mem.e_y == info->mem.f_y)
		{
			if (enemy_encount_y(info))
				return ;
			return ;
		}
		if (enemy_encount_else(info))
			return ;
	}
	if ((info->mem.e_x == info->x && info->mem.e_y == info->y) \
	|| (info->mem.e_x == info->mem.f_x && info->mem.e_y == info->mem.f_y))
		close_window(info);
}
