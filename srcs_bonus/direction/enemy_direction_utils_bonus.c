#include "../includes/so_long_bonus.h"

bool	enemy_direction_y(t_info *info)
{
	if ((info->e_direction != BACK) && (info->mem.e_y < info->y) && \
	((info->map[info->mem.e_y + 1][info->mem.e_x] == '0') \
	|| (info->map[info->mem.e_y + 1][info->mem.e_x] == 'P')))
	{
		info->e_direction = FRONT;
		info->mem.e_y += 1;
		return (true);
	}
	if ((info->e_direction != FRONT) && (info->mem.e_y > info->y) && \
	((info->map[info->mem.e_y - 1][info->mem.e_x] == '0') \
	|| (info->map[info->mem.e_y - 1][info->mem.e_x] == 'P')))
	{
		info->e_direction = BACK;
		info->mem.e_y -= 1;
		return (true);
	}
	return (false);
}

bool	enemy_direction_x(t_info *info)
{
	if ((info->e_direction != LEFT) && (info->mem.e_x < info->x) && \
	((info->map[info->mem.e_y][info->mem.e_x + 1] == '0') \
	|| (info->map[info->mem.e_y][info->mem.e_x + 1] == 'P')))
	{
		info->e_direction = RIGHT;
		info->mem.e_x += 1;
		return (true);
	}
	if (info->e_direction != RIGHT && info->mem.e_x > info->x && \
	(info->map[info->mem.e_y][info->mem.e_x - 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x - 1] == 'P'))
	{
		info->e_direction = LEFT;
		info->mem.e_x -= 1;
		return (true);
	}
	return (false);
}

bool	enemy_direction_else1(t_info *info)
{
	if (info->e_direction != BACK \
	&& (info->map[info->mem.e_y + 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y + 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = FRONT;
		info->mem.e_y += 1;
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

bool	enemy_direction_else2(t_info *info)
{
	if (info->e_direction != FRONT \
	&& (info->map[info->mem.e_y - 1][info->mem.e_x] == '0' \
	|| info->map[info->mem.e_y - 1][info->mem.e_x] == 'P'))
	{
		info->e_direction = BACK;
		info->mem.e_y -= 1;
		return (true);
	}
	if (info->e_direction != RIGHT \
	&& (info->map[info->mem.e_y][info->mem.e_x - 1] == '0' \
	|| info->map[info->mem.e_y][info->mem.e_x - 1] == 'P'))
	{
		info->e_direction = LEFT;
		info->mem.e_x -= 1;
		return (true);
	}
	return (false);
}

bool	enemy_encount_else(t_info *info)
{
	if (enemy_direction_x(info))
		return (true);
	if (enemy_direction_y(info))
		return (true);
	if (enemy_direction_else1(info))
		return (true);
	if (enemy_direction_else2(info))
		return (true);
	return (false);
}
