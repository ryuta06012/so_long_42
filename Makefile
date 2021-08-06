NAME = so_long

NAME_BONUS = so_long_bonus

SRCS_DIR = ./srcs/

SRCS_NAME = main.c animation_pattern/animation_pattern.c \
		checks/check_extension.c \
		checks/check_map_line.c \
		checks/check_position.c \
		checks/map_error_check.c \
		checks/map_wall_check.c \
		close_and_free/close.c \
		close_and_free/free.c \
		close_and_free/close_exit_utils1.c \
		close_and_free/close_exit_utils2.c \
		close_and_free/close_exit.c \
		direction/enemy_direction_utils.c \
		direction/enemy_direction.c \
		direction/fellow_direction.c \
		direction/key_direction_image.c \
		direction/player_direction.c \
		direction/player_fellow_direction.c \
		direction/second_enemy_direction_utils.c \
		direction/second_enemy_direction.c \
		render/draw_image.c \
		struct/init_data_utils.c \
		struct/init_data.c \
		struct/init_image_utils1.c \
		struct/init_image_utils2.c \
		struct/init_player.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

SRCS_BONUS_DIR = ./srcs_bonus/

SRCS_BONUS_NAME = main_bonus.c animation_pattern/animation_pattern_bonus.c \
		checks/check_extension_bonus.c \
		checks/check_map_line_bonus.c \
		checks/check_position_bonus.c \
		checks/map_error_check_bonus.c \
		checks/map_wall_check_bonus.c \
		close_and_free/close_bonus.c \
		close_and_free/free_bonus.c \
		close_and_free/close_exit_utils1_bonus.c \
		close_and_free/close_exit_utils2_bonus.c \
		close_and_free/close_exit_bonus.c \
		direction/enemy_direction_utils_bonus.c \
		direction/enemy_direction_bonus.c \
		direction/fellow_direction_bonus.c \
		direction/key_direction_image_bonus.c \
		direction/player_direction_bonus.c \
		direction/player_fellow_direction_bonus.c \
		direction/second_enemy_direction_utils_bonus.c \
		direction/second_enemy_direction_bonus.c \
		render/draw_image_bonus.c \
		struct/init_data_utils_bonus.c \
		struct/init_data_bonus.c \
		struct/init_image_utils1_bonus.c \
		struct/init_image_utils2_bonus.c \
		struct/init_player_bonus.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c

SRCS_BONUS = ${addprefix ${SRCS_BONUS_DIR}, ${SRCS_BONUS_NAME}}

MAP_SRCS_DIR = ./map/

MAP_NAME = big.ber midiam.ber no_5char.ber no_enemy_space.ber no_rectangular.ber no_surround_wall.ber out_of_5char.ber

MAP_SRCS = ${addprefix ${MAP_SRCS_DIR}, ${MAP_NAME}}

HEADER = ./includes

LIBFT_DIR = ./libft

MLX_DIR = ./minilibx-linux

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ${MLX_DIR} -I ${HEADER} -I ${LIBFT_DIR}

RM = rm -rf

MAKE_BONUS = make bonus

all: ${NAME}

bonus: ${NAME_BONUS}

${NAME}: ${MLX_DIR} ${OBJS} ${HEADER} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE_BONUS} -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft
	@mv ./map/*ber ./
	@export DISPLAY=:0

${NAME_BONUS}: ${MLX_DIR} ${OBJS_BONUS} ${HEADER} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE_BONUS} -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft
	@mv ./map/*ber ./
	@export DISPLAY=:0

${MLX_DIR}:
	git clone https://github.com/42Paris/minilibx-linux.git ${MLX_DIR}

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME} ${NAME_BONUS} ${MLX_DIR}
	@mv ./*ber ./map

re: fclean all

.PHONY: all bonus val val_bonus clean fclean re