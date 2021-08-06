#include "so_long.h"

void	check_map_char(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == '1' || info->map[i][j] == '0' \
			|| info->map[i][j] == 'P' || info->map[i][j] == 'E' \
			|| info->map[i][j] == 'C')
				j++;
			else
			{
				ft_putstr_fd("Error.\nThe map must be composed\
 of only 5 possible characters.\n", 2);
				free_array(info->map);
				exit(1);
			}
		}
		i++;
	}
}

void	cnt_check(t_info *info, int *e_cnt, int *c_cnt, int *p_cnt)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'E')
				*e_cnt = 1;
			if (info->map[i][j] == 'P')
				*p_cnt = 1;
			if (info->map[i][j] == 'C')
				*c_cnt = 1;
			j++;
		}
		i++;
	}
}

void	check_map_e_c_p(t_info *info)
{
	int	e_cnt;
	int	c_cnt;
	int	p_cnt;

	e_cnt = 0;
	c_cnt = 0;
	p_cnt = 0;
	cnt_check(info, &e_cnt, &c_cnt, &p_cnt);
	if (e_cnt == 0 || c_cnt == 0 || p_cnt == 0)
	{
		ft_putstr_fd("Error.\nMap must have at least one exit,\
one collectible, and one starting position..\n", 2);
		free_array(info->map);
		exit(EXIT_FAILURE);
	}
}

void	check_rectangular(t_info *info)
{
	int	tmp;
	int	tmp1;
	int	i;

	i = 0;
	tmp = 0;
	tmp1 = ft_strlen(info->map[0]);
	while (info->map[i] != NULL)
	{
		tmp = ft_strlen(info->map[i]);
		if (tmp != tmp1)
		{
			free_array(info->map);
			ft_putstr_fd("Error.\nThe map must be rectangular.\n", 2);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	map_error_check(t_info *info)
{
	check_map_char(info);
	check_map_e_c_p(info);
	check_rectangular(info);
	map_wall_check(info);
}
