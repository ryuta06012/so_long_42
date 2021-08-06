#include "../includes/so_long_bonus.h"

void	enemy_image_put_image(t_info *info)
{
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
	info->enemy.img, info->mem.e_x * IMAGE_SIZE, info->mem.e_y * IMAGE_SIZE);
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
	info->enemy2.img, info->mem.e2_x * IMAGE_SIZE, info->mem.e2_y * IMAGE_SIZE);
}

void	check_characters(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0' || info->map[i][j] == 'P')
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->floor.img, j * IMAGE_SIZE, i * IMAGE_SIZE);
	if (info->map[i][j] == '1')
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->wall.img, j * IMAGE_SIZE, i * IMAGE_SIZE);
	if (info->map[i][j] == 'C')
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->feed.img, j * IMAGE_SIZE, i * IMAGE_SIZE);
	if (info->map[i][j] == 'E')
	{
		mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
		info->goal.img[info->goal.g_pattern], j * IMAGE_SIZE, i * IMAGE_SIZE);
		info->goal.g_x = j;
		info->goal.g_y = i;
	}
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	if (info->map[info->y][info->x] == 'C')
	{
		info->map[info->y][info->x] = '0';
		info->f_count += 1;
	}
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			check_characters(info, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, info->front.img, \
	info->x * IMAGE_SIZE, info->y * IMAGE_SIZE);
}
