/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:59:48 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:45:57 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_int(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	insert_lb(t_map *map, char *line)
{
	char *temp;

	temp = ft_strjoin(map->mapstr, line);
	free(map->mapstr);
	map->mapstr = temp;
	temp = ft_strjoin(map->mapstr, "\n");
	free(map->mapstr);
	map->mapstr = temp;
}

void	handle_lines(t_map *map, char *line, int i)
{
	if (ft_isalpha(line[i]))
	{
		handle_texres(map, line, i);
		free(line);
	}
	else if (ft_isdigit(line[i]) && map->info_count == 8)
	{
		map_in_string(map, line);
		free(line);
	}
	else
		free(line);
	if (map->mapstr != NULL && ft_strlen(line) == 0)
		map->invalmap_flag = 1;
}

int		read_cub_file(t_map *map, char *path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((get_next_line(fd, &line)) > 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		handle_lines(map, line, i);
	}
	insert_lb(map, line);
	str_to_array2(map);
	free(line);
	return (1);
}
