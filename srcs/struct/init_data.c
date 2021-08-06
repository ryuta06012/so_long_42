#include "so_long.h"

void	init_info(t_info *info)
{
	info->map = NULL;
	info->height = 0;
	info->width = 0;
	info->x = 0;
	info->y = 0;
	info->direction = 0;
	info->direction_pattern = 0;
	info->f_direction = 0;
	info->e_direction = 0;
	info->e2_direction = 0;
	info->f_count = 0;
	info->key = 0;
	info->move_cnt = 0;
	info->e_space = 0;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
}

void	init_mem(t_mem *mem)
{
	mem->feed_count = 0;
	mem->p_x = 0;
	mem->p_y = 0;
	mem->e_x = 0;
	mem->e_y = 0;
	mem->e2_x = 0;
	mem->e2_y = 0;
	mem->f_x = 0;
	mem->f_y = 0;
	mem->e_flag = 0;
	mem->e_count = 0;
}

void	init_g(t_goal *goal)
{
	goal->img[G_PATTERN_NUM] = NULL;
	goal->addr = NULL;
	goal->width = 0;
	goal->height = 0;
	goal->g_x = 0;
	goal->g_y = 0;
	goal->g_pattern = 0;
	goal->g_cnt = 0;
}

void	init_datas(t_info *info)
{
	init_info(info);
	init_data(&info->front);
	init_data(&info->front1);
	init_data(&info->floor);
	init_data(&info->left);
	init_data(&info->left1);
	init_data(&info->right);
	init_data(&info->right1);
	init_data(&info->back);
	init_data(&info->back1);
	init_data(&info->fellow_f);
	init_data(&info->fellow_f1);
	init_data(&info->fellow_l);
	init_data(&info->fellow_l1);
	init_data(&info->fellow_r);
	init_data(&info->fellow_r1);
	init_data(&info->fellow_b);
	init_data(&info->fellow_b1);
	init_data(&info->enemy);
	init_data(&info->enemy2);
	init_data(&info->feed);
	init_data(&info->wall);
	init_g(&info->goal);
}
