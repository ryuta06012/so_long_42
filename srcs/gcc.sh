gcc -Wextra -Werror -Wall main.c ./animation_pattern/animation_pattern.c \
		./checks/check_extension.c \
		./checks/check_map_line.c \
		./checks/check_position.c \
		./checks/map_error_check.c \
		./checks/map_wall_check.c \
		./close_and_free/close.c \
		./close_and_free/free.c \
		./close_and_free/close_exit_utils1.c \
		./close_and_free/close_exit_utils2.c \
		./close_and_free/close_exit.c \
		./direction/enemy_direction_utils.c \
		./direction/enemy_direction.c \
		./direction/fellow_direction.c \
		./direction/key_direction_image.c \
		./direction/player_direction.c \
		./direction/player_fellow_direction.c \
		./direction/second_enemy_direction_utils.c \
		./direction/second_enemy_direction.c \
		./render/draw_image.c \
		./struct/init_data_utils.c \
		./struct/init_data.c \
		./struct/init_image_utils1.c \
		./struct/init_image_utils2.c \
		./struct/init_player.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./includes/so_long.h \
		-L ./libft/ -lft -L ./minilibx-linux/ -lmlx -lXext -lX11
#gcc main.c so_long.h -L ./minilibx-linux/ -lmlx -lXext -lX11
#gcc -I ./minilibx_linux/mlx.h main.c -L ./minilibx-linux/ -lmlx -lXext -lX11
#gcc main.c so_long.h -L ./minilibx-linux/ -lmlx -I ./minilibx_linux/ -lXext -lX11
#./struct/init_player.c
#-g -fsanitize=address
#valgrind --leak-check=full -s ./a.out
