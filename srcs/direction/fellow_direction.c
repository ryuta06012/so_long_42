#include "so_long.h"

void	direction_back_f(t_info *info)
{
	if (info->direction_pattern == 0)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_b.img, info->x * IMAGE_SIZE, (info->y + 1) * IMAGE_SIZE);
	else if (info->direction_pattern == 1)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_b1.img, info->x * IMAGE_SIZE, (info->y + 1) * IMAGE_SIZE);
	info->mem.f_x = info->x;
	info->mem.f_y = info->y + 1;
}

void	direction_front_f(t_info *info)
{
	if (info->direction_pattern == 0)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_f.img, info->x * IMAGE_SIZE, (info->y - 1) * IMAGE_SIZE);
	else if (info->direction_pattern == 1)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_f1.img, info->x * IMAGE_SIZE, (info->y - 1) * IMAGE_SIZE);
	info->mem.f_x = info->x;
	info->mem.f_y = info->y - 1;
}

void	direction_right_f(t_info *info)
{
	if (info->direction_pattern == 0)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_r.img, (info->x - 1) * IMAGE_SIZE, info->y * IMAGE_SIZE);
	else if (info->direction_pattern == 1)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_l1.img, (info->x - 1) * IMAGE_SIZE, info->y * IMAGE_SIZE);
	info->mem.f_x = info->x - 1;
	info->mem.f_y = info->y;
}

void	direction_left_f(t_info *info)
{
	if (info->direction_pattern == 0)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_l.img, (info->x + 1) * IMAGE_SIZE, info->y * IMAGE_SIZE);
	else if (info->direction_pattern == 1)
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->fellow_r1.img, (info->x + 1) * IMAGE_SIZE, info->y * IMAGE_SIZE);
	info->mem.f_x = info->x + 1;
	info->mem.f_y = info->y;
}
