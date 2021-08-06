#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define IMAGE_SIZE		30
# define FRONT	1
# define BACK	2
# define LEFT	3
# define RIGHT	4

enum		e_index
{
	G_3,
	G_4,
	G_5,
	G_6,
	G_7,
	G_8,
	G_9,
	G_10,
	G_PATTERN_NUM
};

typedef struct s_goal
{
	void	*img[G_PATTERN_NUM];
	char	*addr;
	int		width;
	int		height;
	int		g_x;
	int		g_y;
	int		g_pattern;
	int		g_cnt;
}		t_goal;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_mem
{
	int	feed_count;
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;
	int	e2_x;
	int	e2_y;
	int	f_x;
	int	f_y;
	int	e_flag;
	int	e_count;
}		t_mem;

typedef struct s_info
{
	t_data	front;
	t_data	front1;
	t_data	floor;
	t_data	floor1;
	t_data	left;
	t_data	left1;
	t_data	right;
	t_data	right1;
	t_data	back;
	t_data	back1;
	t_data	fellow_f;
	t_data	fellow_f1;
	t_data	fellow_l;
	t_data	fellow_l1;
	t_data	fellow_r;
	t_data	fellow_r1;
	t_data	fellow_b;
	t_data	fellow_b1;
	t_data	feed;
	t_goal	goal;
	t_data	wall;
	t_mem	mem;
	t_data	enemy;
	t_data	enemy2;
	t_vars	vars;
	char	**map;
	int		height;
	int		width;
	int		x;
	int		y;
	int		direction;
	int		f_direction;
	int		e_direction;
	int		e2_direction;
	int		f_count;
	int		direction_pattern;
	int		key;
	int		move_cnt;
	int		e_space;
}		t_info;

/* ./animation_pattern/animation_pattern.c */
void	goal_animation_pattern(t_info *info, int *i);
void	run_animation_pattern(t_info *info, int *i);

/* ./checks/check_extension.c */
int		to_upper(int c);
int		check_so_long_extension(char *str, char *ext);

/* ./checks/check_map_line.c */
char	**map_line(t_list *new_list, t_info *info);
bool	read_map(t_info *info, t_list *new_list);
t_list	*gnl_map(int status, int fd);
bool	read_map_lines(char **argv, t_info *info);

/* ./checks/check_position.c */
bool	enemy_disposition(t_info *info);
void	first_enemy_position(t_info *info);
void	second_enemy_position(t_info *info);
void	enemy_position(t_info *info);
void	player_feed_position(t_info *info);

/* ./checks/map_error_check.c */
void	check_map_char(t_info *info);
void	cnt_check(t_info *info, int *e_cnt, int *c_cnt, int *p_cnt);
void	check_map_e_c_p(t_info *info);
void	check_rectangular(t_info *info);
void	map_error_check(t_info *info);

/* ./checks/map_wall_check.c */
bool	map_wall_check_width(t_info *info);
bool	map_wall_check_height(t_info *info);
void	map_wall_check(t_info *info);

/* ./close_and_free/close.c */
void	close_goal_image_window(t_info *info);
void	close_player_image_window(t_info *info);
void	close_enemy_image_window(t_info *info);
void	close_else_image_window(t_info *info);
int		close_window(t_info *info);

/* ./close_and_free/free.c */
void	free_line(void *line);
void	free_array(char **array);

/* ./close_and_free/close_exit.c */
void	null_check1(t_info *info, int *flag);
void	null_check2(t_info *info, int *flag);
void	exit_close(t_info *info);
void	img_null_check(t_info *info);

/* ./close_and_free/close_exit_utils1.c */
void	front_img_null_check(t_info *info);
void	back_img_null_check(t_info *info);
void	right_img_null_check(t_info *info);
void	left_img_null_check(t_info *info);
void	feed_img_null_check(t_info *info);

/* ./close_and_free/close_exit_utils2.c */
void	goal_img_null_check(t_info *info);
void	wall_img_null_check(t_info *info);
void	floor_img_null_check(t_info *info);
void	enemy_img_null_check(t_info *info);

/* ./direction/enemy_direction_utils.c */
bool	enemy_direction_y(t_info *info);
bool	enemy_direction_x(t_info *info);
bool	enemy_direction_else1(t_info *info);
bool	enemy_direction_else2(t_info *info);
bool	enemy_encount_else(t_info *info);

/* ./direction/enemy_direction.c */
bool	enemy_encount_x_dir(t_info *info);
bool	enemy_encount_x(t_info *info);
bool	enemy_encount_y_dir(t_info *info);
bool	enemy_encount_y(t_info *info);
void	enemy_encounter(t_info *info, int *cnt);

/* ./direction/fellow_direction.c */
void	direction_back_f(t_info *info);
void	direction_front_f(t_info *info);
void	direction_right_f(t_info *info);
void	direction_left_f(t_info *info);

/* ./direction/key_direction_image.c */
int		key_direction_image(t_info *info);
void	direction_put_image(t_info *info);

/* ./direction/player_direction.c */
void	direction_zero(t_info *info);
void	direction_back(t_info *info);
void	direction_front(t_info *info);
void	direction_right(t_info *info);
void	direction_left(t_info *info);

/* ./direction/player_fellow_direction.c */
void	turn_up(t_info *info);
void	turn_down(t_info *info);
void	turn_right(t_info *info);
void	turn_left(t_info *info);

/* ./direction/second_enemy_direction_utils.c */
bool	second_enemy_encount_dirction_x(t_info *info);
bool	second_enemy_encount_dirction_y(t_info *info);
bool	second_enemy_encount_dirction_else1(t_info *info);
bool	second_enemy_encount_dirction_else2(t_info *info);
bool	second_enemy_encount_else(t_info *info);

/* ./direction/second_enemy_direction.c */
bool	second_enemy_encount_x_dir(t_info *info);
bool	second_enemy_encount_x(t_info *info);
bool	second_enemy_encount_y_dir(t_info *info);
bool	second_enemy_encount_y(t_info *info);
void	second_enemy_encounter(t_info *info, int *cnt);

/* ./render/draw_image.c */
void	enemy_image_put_image(t_info *info);
void	check_characters(t_info *info, int i, int j);
void	draw_map(t_info *info);

/* ./struct/init_data_utils.c */
void	init_data(t_data *data);

/* ./struct/init_data.c */
void	init_info(t_info *info);
void	init_vars(t_vars *vars);
void	init_mem(t_mem *mem);
void	init_g(t_goal *goal);
void	init_datas(t_info *info);

/* ./struct/init_image_utils1.c */
void	init_feed(t_info *info);
void	init_goal2(t_info *info);
void	init_goal1(t_info *info);
void	init_wall(t_info *info);

/* ./struct/init_image_utils2.c */
void	init_floor(t_info *info);
void	init_enemy(t_info *info);
void	init_enemy2(t_info *info);

/* ./struct/init_player.c */
void	init_left(t_info *info);
void	init_right(t_info *info);
void	init_back(t_info *info);
void	init_front(t_info *info);
void	init_player(t_info *info);

#endif
