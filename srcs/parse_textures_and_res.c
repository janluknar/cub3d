/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_and_res.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:49:22 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:45:18 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_res(t_map *map, char *line, int i)
{
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map->width += line[i] - '0';
		map->width *= 10;
		i++;
	}
	map->width /= 10;
	while (line[i] == ' ')
		i++;
	map->height = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map->height += line[i] - '0';
		map->height *= 10;
		i++;
	}
	map->height /= 10;
}

void		get_texpath2(t_map *map, char *line, int i)
{
	if (line[i] == 'W')
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		map->west = ft_substr(line, i, ft_strlen(line) - i);
	}
	if (line[i] == 'E')
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		map->east = ft_substr(line, i, ft_strlen(line) - i);
	}
}

void		get_texpath(t_map *map, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == ' ')
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		map->sprite = ft_substr(line, i, ft_strlen(line) - i);
	}
	if (line[i] == 'N')
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		map->north = ft_substr(line, i, ft_strlen(line) - i);
	}
	if (line[i] == 'S')
	{
		i += 2;
		while (line[i] == ' ')
			i++;
		map->south = ft_substr(line, i, ft_strlen(line) - i);
	}
	get_texpath2(map, line, i);
}

void		get_colors(t_map *map, char *line, int i)
{
	map->red = 0;
	map->green = 0;
	map->blue = 0;
	while (line[i] == ' ')
		i++;
	map->red = ft_atoi(&line[i]);
	i += numlen(map->red) + 1;
	while (line[i] == ' ')
		i++;
	map->green = ft_atoi(&line[i]);
	i += numlen(map->green) + 1;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map->blue += line[i] - '0';
		map->blue *= 10;
		i++;
	}
	map->blue /= 10;
	if (map->fc_flag)
		map->floor = rgb_int(map->red, map->green, map->blue);
	else
		map->ceiling = rgb_int(map->red, map->green, map->blue);
}

void		handle_texres(t_map *map, char *line, int i)
{
	map->fc_flag = 0;
	if (line[i] == 'R')
	{
		i += 2;
		get_res(map, line, i);
	}
	else if ((line[i] == 'N' && line[i + 1] == 'O')
	|| (line[i] == 'S' && line[i + 1] == 'O')
	|| (line[i] == 'W' && line[i + 1] == 'E')
	|| (line[i] == 'E' && line[i + 1] == 'A')
	|| (line[i] == 'S' && line[i + 1] == ' '))
		get_texpath(map, line, i);
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
			map->fc_flag = 1;
		i += 2;
		get_colors(map, line, i);
	}
	map->info_count++;
}
