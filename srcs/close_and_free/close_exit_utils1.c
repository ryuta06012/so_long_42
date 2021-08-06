#include "so_long.h"

void	front_img_null_check(t_info *info)
{
	if (info->front.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->front.img);
	if (info->front1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->front1.img);
	if (info->fellow_f1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_f1.img);
	if (info->fellow_f.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_f.img);
}

void	back_img_null_check(t_info *info)
{
	if (info->back.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->back.img);
	if (info->back1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->back1.img);
	if (info->fellow_b.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_b.img);
	if (info->fellow_b1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_b1.img);
}

void	right_img_null_check(t_info *info)
{
	if (info->right.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->right.img);
	if (info->right1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->right1.img);
	if (info->fellow_r.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_r.img);
	if (info->fellow_r1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_r1.img);
}

void	left_img_null_check(t_info *info)
{
	if (info->left.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->left.img);
	if (info->left1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->left1.img);
	if (info->fellow_l.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_l.img);
	if (info->fellow_l1.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->fellow_l1.img);
}

void	feed_img_null_check(t_info *info)
{
	if (info->feed.img != NULL)
		mlx_destroy_image(info->vars.mlx, info->feed.img);
}
