#include "../includes/so_long_bonus.h"

void	init_feed(t_info *info)
{
	char	*feed_path;

	feed_path = "./image_folder/feed.xpm";
	info->feed.img = mlx_xpm_file_to_image(info->vars.mlx, \
	feed_path, &info->feed.width, &info->feed.height);
}

void	init_goal2(t_info *info)
{
	char	*goal7_path;
	char	*goal8_path;
	char	*goal9_path;
	char	*goal10_path;

	goal7_path = "./image_folder/pattern7_g.xpm";
	goal8_path = "./image_folder/pattern8_g.xpm";
	goal9_path = "./image_folder/pattern9_g.xpm";
	goal10_path = "./image_folder/pattern10_g.xpm";
	info->goal.img[G_7] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal7_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_8] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal8_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_9] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal9_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_10] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal10_path, &info->goal.width, &info->goal.height);
}

void	init_goal1(t_info *info)
{
	char	*goal3_path;
	char	*goal4_path;
	char	*goal5_path;
	char	*goal6_path;

	goal3_path = "./image_folder/pattern3_g.xpm";
	goal4_path = "./image_folder/pattern4_g.xpm";
	goal5_path = "./image_folder/pattern5_g.xpm";
	goal6_path = "./image_folder/pattern6_g.xpm";
	info->goal.img[G_3] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal3_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_4] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal4_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_5] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal5_path, &info->goal.width, &info->goal.height);
	info->goal.img[G_6] = mlx_xpm_file_to_image(info->vars.mlx, \
	goal6_path, &info->goal.width, &info->goal.height);
	init_goal2(info);
}

void	init_wall(t_info *info)
{
	char	 *wall_path;

	wall_path = "./image_folder/wall.xpm";
	info->wall.img = mlx_xpm_file_to_image(info->vars.mlx, \
	wall_path, &info->wall.width, &info->wall.height);
}
