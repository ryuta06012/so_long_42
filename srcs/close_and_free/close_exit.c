#include "so_long.h"

void	null_check1(t_info *info, int *flag)
{
	if (info->left.img == NULL \
	|| info->fellow_l.img == NULL \
	|| info->left1.img == NULL \
	|| info->fellow_l1.img == NULL \
	|| info->right.img == NULL \
	|| info->fellow_r.img == NULL \
	|| info->right1.img == NULL \
	|| info->fellow_r1.img == NULL \
	|| info->back.img == NULL \
	|| info->fellow_b.img == NULL \
	|| info->back1.img == NULL \
	|| info->fellow_b1.img == NULL \
	|| info->front.img == NULL)
		*flag = 1;
}

void	null_check2(t_info *info, int *flag)
{
	if (info->fellow_f.img == NULL \
	|| info->front1.img == NULL \
	|| info->fellow_f1.img == NULL \
	|| info->feed.img == NULL \
	|| info->goal.img[G_3] == NULL \
	|| info->goal.img[G_4] == NULL \
	|| info->goal.img[G_5] == NULL \
	|| info->goal.img[G_6] == NULL \
	|| info->goal.img[G_7] == NULL \
	|| info->goal.img[G_8] == NULL \
	|| info->goal.img[G_9] == NULL \
	|| info->goal.img[G_10] == NULL \
	|| info->wall.img == NULL \
	|| info->floor.img == NULL \
	|| info->enemy.img == NULL \
	|| info->enemy2.img == NULL)
		*flag = 1;
}

void	exit_close(t_info *info)
{
	front_img_null_check(info);
	back_img_null_check(info);
	right_img_null_check(info);
	left_img_null_check(info);
	feed_img_null_check(info);
	goal_img_null_check(info);
	wall_img_null_check(info);
	floor_img_null_check(info);
	enemy_img_null_check(info);
	mlx_destroy_window(info->vars.mlx, info->vars.win);
	mlx_destroy_display(info->vars.mlx);
	free(info->vars.mlx);
	free_array(info->map);
	exit(1);
}

void	img_null_check(t_info *info)
{
	int	flag1;
	int	flag2;

	flag1 = 0;
	flag2 = 0;
	null_check1(info, &flag1);
	null_check2(info, &flag2);
	if (flag1 == 1 || flag2 == 1)
		exit_close(info);
}
