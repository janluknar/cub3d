/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:42:47 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:45:46 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_in_string(t_map *map, char *line)
{
	char	*temp;

	if (!map->mapstr)
	{
		map->mapstr = ft_strdup("");
	}
	temp = ft_strjoin(map->mapstr, line);
	free(map->mapstr);
	map->mapstr = ft_strdup(temp);
	free(temp);
	temp = ft_strjoin(map->mapstr, "\n");
	free(map->mapstr);
	map->mapstr = ft_strdup(temp);
	free(temp);
}

void	get_collumnns(t_map *map)
{
	int i;
	int j;
	int collumns_old;

	i = 0;
	j = 0;
	collumns_old = 0;
	while (map->mapstr[i] != '\0')
	{
		if (ft_isdigit(map->mapstr[i]) || map->mapstr[i] == '\n'
		|| map->mapstr[i] == ' ')
		{
			j++;
			if (map->mapstr[i] == '\n')
			{
				map->collumns = j - 1;
				if (map->collumns < collumns_old)
					map->collumns = collumns_old;
				else
					collumns_old = map->collumns;
				j = 0;
			}
		}
		i++;
	}
}

void	get_rows_collumns(t_map *map)
{
	int i;

	i = 0;
	get_collumnns(map);
	map->rows = 0;
	while (map->mapstr[i] != '\0')
	{
		if (ft_isdigit(map->mapstr[i]) || map->mapstr[i] == '\n'
			|| map->mapstr[i] == ' ')
		{
			if (map->mapstr[i] == ' ')
				map->mapstr[i] = '3';
			if (map->mapstr[i] == '\n')
				map->rows++;
			else if (map->mapstr[i] == '2')
				map->numsprites++;
		}
		i++;
	}
}

void	fill_plane(t_map *map)
{
	int y;
	int x;

	if (!(map->maparray = malloc(sizeof(int*) * map->rows)))
		return ;
	y = 0;
	while (y < map->rows)
	{
		if (!(map->maparray[y] = malloc(sizeof(int) * map->collumns)))
			return ;
		x = 0;
		while (x < map->collumns)
		{
			map->maparray[y][x] = 3;
			x++;
		}
		y++;
	}
}

void	get_spawn(t_map *map, int y, int x)
{
	if (map->strarr[y][x] == 'N')
		map->spawn = 'N';
	else if (map->strarr[y][x] == 'S')
		map->spawn = 'S';
	else if (map->strarr[y][x] == 'W')
		map->spawn = 'W';
	else if (map->strarr[y][x] == 'E')
		map->spawn = 'E';
	else
	{
		map->posy = -1;
		map->posx = -1;
		map->spawn = 'X';
		map->maparray[y][x] = 3;
		return ;
	}
	map->maparray[y][x] = 0;
	map->posy = y;
	map->posx = x;
	map->spawnflag = 1;
}
