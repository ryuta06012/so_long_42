#include "so_long.h"

void	turn_up(t_info *info)
{
	info->direction = BACK;
	if (info->y == 0)
		return ;
	else if (info->map[info->y - 1][info->x] == '1' \
	|| (info->map[info->y - 1][info->x] == 'E' \
	&& info->f_count != info->mem.feed_count))
		return ;
	else
	{
		info->move_cnt++;
		info->f_direction = BACK;
		info->y -= 1;
	}
}

void	turn_down(t_info *info)
{
	info->direction = FRONT;
	if (info->y == info->height - 1)
		return ;
	else if (info->map[info->y + 1][info->x] == '1' \
	|| (info->map[info->y + 1][info->x] == 'E' \
	&& info->f_count != info->mem.feed_count))
		return ;
	else
	{
		info->move_cnt++;
		info->f_direction = FRONT;
		info->y += 1;
	}
}

void	turn_right(t_info *info)
{
	info->direction = RIGHT;
	if (info->x == info->width - 1)
		return ;
	else if (info->map[info->y][info->x + 1] == '1' \
	|| (info->map[info->y][info->x + 1] == 'E' \
	&& info->f_count != info->mem.feed_count))
		return ;
	else
	{
		info->move_cnt++;
		info->f_direction = RIGHT;
		info->x += 1;
	}	
}

void	turn_left(t_info *info)
{
	info->direction = LEFT;
	if (info->x == 0)
		return ;
	else if (info->map[info->y][info->x - 1] == '1' \
	|| (info->map[info->y][info->x - 1] == 'E' \
	&& info->f_count != info->mem.feed_count))
		return ;
	else
	{
		info->move_cnt++;
		info->f_direction = LEFT;
		info->x -= 1;
	}
}
