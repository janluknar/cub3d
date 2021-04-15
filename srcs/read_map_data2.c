/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_data2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:13:40 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 09:34:52 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strarr_to_intarr(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (map->strarr[y] != NULL)
	{
		x = 0;
		while (map->strarr[y][x] != '\0')
		{
			if (ft_isalpha(map->strarr[y][x]))
				get_spawn(map, y, x);
			else
				map->maparray[y][x] = map->strarr[y][x] - 48;
			x++;
		}
		y++;
	}
}

void	str_to_array2(t_map *map)
{
	int y;
	int x;

	get_rows_collumns(map);
	map->strarr = ft_split(map->mapstr, '\n');
	y = 0;
	while (map->strarr[y] != NULL)
	{
		x = 0;
		while (map->strarr[y][x] != '\0')
			x++;
		y++;
	}
	fill_plane(map);
	strarr_to_intarr(map);
}
