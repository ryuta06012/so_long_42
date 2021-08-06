#include "so_long.h"

void	init_floor(t_info *info)
{
	char	*floor_path;

	floor_path = "./image_folder/floor.xpm";
	info->floor.img = mlx_xpm_file_to_image(info->vars.mlx, \
	floor_path, &info->floor.width, &info->floor.height);
}

void	init_enemy(t_info *info)
{
	char	*enemy_back_path;

	enemy_back_path = "./image_folder/player_back.xpm";
	info->enemy.img = mlx_xpm_file_to_image(info->vars.mlx, \
	enemy_back_path, &info->back.width, &info->back.height);
}

void	init_enemy2(t_info *info)
{
	char	*enemy_back_path;

	enemy_back_path = "./image_folder/pattern1_back_p.xpm";
	info->enemy2.img = mlx_xpm_file_to_image(info->vars.mlx, \
	enemy_back_path, &info->back.width, &info->back.height);
}
