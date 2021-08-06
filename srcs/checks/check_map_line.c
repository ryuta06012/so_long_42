#include "so_long.h"

char	**map_line(t_list *new_list, t_info *info)
{
	char	**map;
	int		i;

	info->height = ft_lstsize(new_list);
	info->width = ft_strlen(new_list->content);
	map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (new_list != NULL)
	{
		map[i] = new_list->content;
		new_list->content = NULL;
		new_list = new_list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

bool	read_map(t_info *info, t_list *new_list)
{
	info->map = map_line(new_list, info);
	if (info->map == NULL)
	{
		ft_lstclear(&new_list, free_line);
		return (false);
	}
	else
		ft_lstclear(&new_list, free_line);
	player_feed_position(info);
	return (true);
}

t_list	*gnl_map(int status, int fd)
{
	char	*line;
	t_list	*new_sub_list;
	t_list	*new_list;

	new_sub_list = NULL;
	new_list = NULL;
	while (status == 1)
	{
		status = get_next_line(fd, &line);
		if (status == -1)
		{
			ft_lstclear(&new_list, free_line);
			return (NULL);
		}
		new_sub_list = ft_lstnew(line);
		if (new_sub_list == NULL)
		{
			ft_lstclear(&new_list, free_line);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_sub_list);
	}
	return (new_list);
}

bool	read_map_lines(char **argv, t_info *info)
{
	int		status;
	int		fd;
	char	*file_name;
	t_list	*new_list;

	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	status = 1;
	new_list = NULL;
	new_list = gnl_map(status, fd);
	if (new_list == NULL)
		return (false);
	if (!read_map(info, new_list))
	{
		if (info->map != NULL)
			free_array(info->map);
		return (false);
	}
	close(fd);
	return (true);
}
