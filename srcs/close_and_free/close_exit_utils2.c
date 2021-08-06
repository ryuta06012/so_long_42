#include "so_long.h"

void	goal_img_null_check(t_info *info)
{
	if (info->goal.img[G_3] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_3]);
	if (info->goal.img[G_4] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_4]);
	if (info->goal.img[G_5] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_5]);
	if (info->goal.img[G_6] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_6]);
	if (info->goal.img[G_7] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_7]);
	if (info->goal.img[G_8] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_8]);
	if (info->goal.img[G_9] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_9]);
	if (info->goal.img[G_10] != NULL)
		mlx_destroy_image(info->vars.mlx, info->goal.img[G_10]);
}

void	wall_img_null_check(t_info *info)
{
	if (info->wall.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->wall.img);
}

void	floor_img_null_check(t_info *info)
{
	if (info->floor.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->floor.img);
}

void	enemy_img_null_check(t_info *info)
{
	if (info->enemy.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->enemy.img);
	if (info->enemy2.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->enemy2.img);
}
