#include "../includes/so_long_bonus.h"

void	goal_animation_pattern(t_info *info, int *i)
{
	if (*i % 100 == 0)
	{
		info->goal.g_pattern++;
		if (info->goal.g_pattern == G_PATTERN_NUM)
			info->goal.g_pattern = 0;
	}
}

void	run_animation_pattern(t_info *info, int *i)
{
	goal_animation_pattern(info, i);
	if (*i % 500 == 0)
		info->direction_pattern = 1;
	if (*i % 1000 == 0)
		info->direction_pattern = 0;
}
