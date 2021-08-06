#include "so_long.h"

bool	second_enemy_encount_dirction_x(t_info *info)
{
	if (info->e2_direction != LEFT && info->mem.e2_x < info->x \
	&& (info->map[info->mem.e2_y][info->mem.e2_x + 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x + 1] == 'P'))
	{
		info->e2_direction = RIGHT;
		info->mem.e2_x += 1;
		return (true);
	}
	if (info->e2_direction != RIGHT && info->mem.e2_x > info->x \
	&& (info->map[info->mem.e2_y][info->mem.e2_x - 1] == '0' \
	|| info->map[info->mem.e2_y][info->mem.e2_x - 1] == 'P'))
	{
		info->e2_direction = LEFT;
		info->mem.e2_x -= 1;
		return (true);
	}
	return (false);
}

bool	second_enemy_encount_dirction_y(t_info *info)
{
	if (info->e2_direction != BACK && info->mem.e2_y < info->y \
	&& (info->map[info->mem.e2_y + 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y + 1][info->mem.e2_x] == 'P'))
	{
		info->e2_direction = FRONT;
		info->mem.e2_y += 1;
		return (true);
	}
	if (info->e2_direction != FRONT && info->mem.e2_y > info->y \
	&& (info->map[info->mem.e2_y - 1][info->mem.e2_x] == '0' \
	|| info->map[info->mem.e2_y - 1][info->mem.e2_x] == 'P'))
	{
		info->e2_direction = BACK;
		info->mem.e2_y -= 1;
		return (true);
	}
	return (false);
}

bool	second_enemy_encount_dirction_else1(t_info *info)
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

bool	second_enemy_encount_dirction_else2(t_info *info)
{
	if (info->e_direction != RIGHT \
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

bool	second_enemy_encount_else(t_info *info)
{
	if (second_enemy_encount_dirction_x(info))
		return (true);
	if (second_enemy_encount_dirction_y(info))
		return (true);
	if (second_enemy_encount_dirction_else1(info))
		return (true);
	if (second_enemy_encount_dirction_else2(info))
		return (true);
	return (false);
}
