#include "../includes/so_long_bonus.h"

void	direction_zero(t_info *info)
{
	if (info->direction_pattern == 0)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->front.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
	else if (info->direction_pattern == 1)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->front1.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
}

void	direction_back(t_info *info)
{
	if (info->direction_pattern == 0)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->back.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
	else if (info->direction_pattern == 1)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->back1.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
}

void	direction_front(t_info *info)
{
	if (info->direction_pattern == 0)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->front.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
	else if (info->direction_pattern == 1)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->front1.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
}

void	direction_right(t_info *info)
{
	if (info->direction_pattern == 0)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->right.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
	else if (info->direction_pattern == 1)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->right1.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
}

void	direction_left(t_info *info)
{
	if (info->direction_pattern == 0)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->left.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
	else if (info->direction_pattern == 1)
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->left1.img, info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
	}
}
