#include "so_long.h"

void	init_left(t_info *info)
{
	char	*left_path;
	char	*left_fellow_path;
	char	*left1_path;
	char	*left_fellow1_path;

	left_path = "./image_folder/player_left.xpm";
	left_fellow_path = "./image_folder/fellow_left.xpm";
	left1_path = "./image_folder/pattern1_left_p.xpm";
	left_fellow1_path = "./image_folder/pattern1_left_f.xpm";
	info->left.img = mlx_xpm_file_to_image(info->vars.mlx, \
	left_path, &info->left.width, &info->left.height);
	info->fellow_l.img = mlx_xpm_file_to_image(info->vars.mlx, \
	left_fellow_path, &info->fellow_l.width, &info->fellow_l.height);
	info->left1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	left1_path, &info->left1.width, &info->left1.height);
	info->fellow_l1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	left_fellow1_path, &info->fellow_l1.width, &info->fellow_l1.height);
}

void	init_right(t_info *info)
{
	char	*right_path;
	char	*right_fellow_path;
	char	*right1_path;
	char	*right_fellow1_path;

	right_path = "./image_folder/player_right.xpm";
	right_fellow_path = "./image_folder/fellow_right.xpm";
	right1_path = "./image_folder/pattern1_right_p.xpm";
	right_fellow1_path = "./image_folder/pattern1_right_f.xpm";
	info->right.img = mlx_xpm_file_to_image(info->vars.mlx, \
	right_path, &info->right.width, &info->right.height);
	info->fellow_r.img = mlx_xpm_file_to_image(info->vars.mlx, \
	right_fellow_path, &info->fellow_r.width, &info->fellow_r.height);
	info->right1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	right1_path, &info->right1.width, &info->right1.height);
	info->fellow_r1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	right_fellow1_path, &info->fellow_r1.width, &info->fellow_r1.height);
}

void	init_back(t_info *info)
{
	char	*back_path;
	char	*back_fellow_path;
	char	*back1_path;
	char	*back_fellow1_path;

	back_path = "./image_folder/player_back.xpm";
	back_fellow_path = "./image_folder/fellow_back.xpm";
	back1_path = "./image_folder/pattern1_back_p.xpm";
	back_fellow1_path = "./image_folder/pattern1_back_f.xpm";
	info->back.img = mlx_xpm_file_to_image(info->vars.mlx, \
	back_path, &info->back.width, &info->back.height);
	info->fellow_b.img = mlx_xpm_file_to_image(info->vars.mlx, \
	back_fellow_path, &info->fellow_b.width, &info->fellow_b.height);
	info->back1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	back1_path, &info->back1.width, &info->back1.height);
	info->fellow_b1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	back_fellow1_path, &info->fellow_b1.width, &info->fellow_b1.height);
}

void	init_front(t_info *info)
{
	char	*front_path;
	char	*front_fellow_path;
	char	*front1_path;
	char	*front_fellow1_path;

	front_path = "./image_folder/player_front.xpm";
	front_fellow_path = "./image_folder/fellow_front.xpm";
	front1_path = "./image_folder/pattern1_front_p.xpm";
	front_fellow1_path = "./image_folder/pattern1_front_f.xpm";
	info->front.img = mlx_xpm_file_to_image(info->vars.mlx, \
	front_path, &info->front.width, &info->front.height);
	info->fellow_f.img = mlx_xpm_file_to_image(info->vars.mlx, \
	front_fellow_path, &info->fellow_f.width, &info->fellow_f.height);
	info->front1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	front1_path, &info->front.width, &info->front.height);
	info->fellow_f1.img = mlx_xpm_file_to_image(info->vars.mlx, \
	front_fellow1_path, &info->fellow_f1.width, &info->fellow_f1.height);
}

void	init_player(t_info *info)
{
	init_front(info);
	init_left(info);
	init_right(info);
	init_back(info);
	init_floor(info);
	init_feed(info);
	init_goal1(info);
	init_wall(info);
	init_enemy(info);
	init_enemy2(info);
}
