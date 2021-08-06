#include "../includes/so_long_bonus.h"

void	close_goal_image_window(t_info *info)
{
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_3]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_4]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_5]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_6]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_7]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_8]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_9]);
	mlx_destroy_image(info->vars.mlx, info->goal.img[G_10]);
}

void	close_player_image_window(t_info *info)
{
	mlx_destroy_image(info->vars.mlx, info->front.img);
	mlx_destroy_image(info->vars.mlx, info->front1.img);
	mlx_destroy_image(info->vars.mlx, info->back.img);
	mlx_destroy_image(info->vars.mlx, info->back1.img);
	mlx_destroy_image(info->vars.mlx, info->left.img);
	mlx_destroy_image(info->vars.mlx, info->left1.img);
	mlx_destroy_image(info->vars.mlx, info->right.img);
	mlx_destroy_image(info->vars.mlx, info->right1.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_f.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_f1.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_b.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_b1.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_l.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_l1.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_r.img);
	mlx_destroy_image(info->vars.mlx, info->fellow_r1.img);
}

void	close_enemy_image_window(t_info *info)
{
	mlx_destroy_image(info->vars.mlx, info->enemy.img);
	mlx_destroy_image(info->vars.mlx, info->enemy2.img);
}

void	close_else_image_window(t_info *info)
{
	mlx_destroy_image(info->vars.mlx, info->floor.img);
	mlx_destroy_image(info->vars.mlx, info->feed.img);
	mlx_destroy_image(info->vars.mlx, info->wall.img);
}

int	close_window(t_info *info)
{
	close_goal_image_window(info);
	close_player_image_window(info);
	close_enemy_image_window(info);
	close_else_image_window(info);
	mlx_destroy_window(info->vars.mlx, info->vars.win);
	mlx_destroy_display(info->vars.mlx);
	free(info->vars.mlx);
	free_array(info->map);
	exit(0);
}
