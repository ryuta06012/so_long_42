#include "so_long.h"

int	key_hook(int keycode, t_info *info)
{
	info->key = keycode;
	return (0);
}

int	map_draw_loop(t_info *info)
{
	static int	cnt;

	run_animation_pattern(info, &cnt);
	key_direction_image(info);
	direction_put_image(info);
	if (info->e_space == 1)
	{
		enemy_encounter(info, &cnt);
		second_enemy_encounter(info, &cnt);
	}
	draw_map(info);
	direction_put_image(info);
	if (info->e_space == 1)
	{
		enemy_image_put_image(info);
	}
	info->key = 0;
	printf("\033[2J\033[4A");
	printf("move : %d\n", info->move_cnt);
	printf("collectible : %d/%d\n", info->f_count, info->mem.feed_count);
	if (cnt == 1000)
		cnt = 0;
	cnt++;
	return (0);
}

void	loop_hook(t_info *info)
{
	mlx_key_hook(info->vars.win, key_hook, info);
	mlx_loop_hook(info->vars.mlx, map_draw_loop, info);
	mlx_hook(info->vars.win, 33, 1L << 17, close_window, info);
	mlx_loop(info->vars.mlx);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	info.x = 0;
	info.y = 0;
	info.mem.f_x = 0;
	info.mem.f_y = 0;
	if (argc == 2)
	{
		check_so_long_extension(argv[1], ".ber");
		init_datas(&info);
		if (!read_map_lines(argv, &info))
			return (-1);
		map_error_check(&info);
		info.vars.mlx = mlx_init();
		info.vars.win = mlx_new_window(info.vars.mlx, info.width * IMAGE_SIZE, \
		info.height * IMAGE_SIZE, "Hello World!");
		init_player(&info);
		img_null_check(&info);
		enemy_position(&info);
		draw_map(&info);
		loop_hook(&info);
	}
	else
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
	return (0);
}
