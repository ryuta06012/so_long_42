#include "so_long.h"

int	key_direction_image(t_info *info)
{
	if ((info->key == 119 && info->y > 0) \
	|| (info->key == 119 && info->y == 0))
		turn_up(info);
	if ((info->key == 115 && info->y < info->height - 1) \
	|| (info->key == 115 && info->y == info->height - 1))
		turn_down(info);
	if ((info->key == 100 && info->x < info->width - 1) \
	|| (info->key == 100 && info->x == info->width - 1))
		turn_right(info);
	if ((info->key == 97 && info->x > 0) \
	|| (info->key == 97 && info->x == 0))
		turn_left(info);
	if (info->key == 65307)
		close_window(info);
	if (info->map[info->y][info->x] == 'E' \
	&& info->f_count == info->mem.feed_count)
		close_window(info);
	return (0);
}

/* playerとenemyを別々に方向で表示させる */
void	direction_put_image(t_info *info)
{
	if (info->direction == 0)
		direction_zero(info);
	if (info->direction == BACK)
		direction_back(info);
	if (info->direction == FRONT)
		direction_front(info);
	if (info->direction == RIGHT)
		direction_right(info);
	if (info->direction == LEFT)
		direction_left(info);
	if (info->f_direction == BACK)
		direction_back_f(info);
	if (info->f_direction == FRONT)
		direction_front_f(info);
	if (info->f_direction == RIGHT)
		direction_right_f(info);
	if (info->f_direction == LEFT)
		direction_left_f(info);
}
