/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:27:44 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/01 12:51:53 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_res(t_mlx *mlx)
{
	if (mlx->map->width > 2560 || mlx->map->height > 1395)
	{
		mlx->map->width = 2560;
		mlx->map->height = 1395;
	}
}

int		check_top_bottom_row(t_mlx *mlx, int x)
{
	int max;

	max = mlx->map->rows - 1;
	while (x < mlx->map->collumns)
	{
		if (mlx->map->maparray[0][x] == 0 || mlx->map->maparray[0][x] == 2)
		{
			if (mlx->map->maparray[1][x] == 3 || mlx->map->maparray[1][x] == 0)
				return (0);
		}
		x++;
	}
	x = 0;
	while (x < mlx->map->collumns)
	{
		if (mlx->map->maparray[max][x] == 0 || mlx->map->maparray[max][x] == 2)
		{
			if (mlx->map->maparray[max - 1][x] == 3
			|| mlx->map->maparray[max - 1][x] == 0)
				return (0);
		}
		x++;
	}
	return (1);
}

int		check_left_right_collumns(t_mlx *mlx, int y)
{
	int max;

	max = mlx->map->collumns - 1;
	while (y < mlx->map->rows)
	{
		if (mlx->map->maparray[y][1] == 0 || mlx->map->maparray[y][1] == 2)
		{
			if (mlx->map->maparray[y][0] == 3 || mlx->map->maparray[y][0] == 0)
				return (0);
		}
		y++;
	}
	y = 0;
	while (y < mlx->map->rows)
	{
		if (mlx->map->maparray[y][max] == 0 || mlx->map->maparray[y][max] == 2)
		{
			if (mlx->map->maparray[y][max - 1] == 3
			|| mlx->map->maparray[y][max - 1] == 0)
				return (0);
		}
		y++;
	}
	return (1);
}

int		check_rest(t_mlx *mlx)
{
	int y;
	int x;

	y = 1;
	while (y < mlx->map->rows - 1)
	{
		x = 1;
		while (x < mlx->map->collumns - 1)
		{
			if (mlx->map->maparray[y][x] == 0 || mlx->map->maparray[y][x] == 2)
			{
				if (mlx->map->maparray[y][x - 1] == 3)
					return (0);
				else if (mlx->map->maparray[y][x + 1] == 3)
					return (0);
				else if (mlx->map->maparray[y - 1][x] == 3)
					return (0);
				else if (mlx->map->maparray[y + 1][x] == 3)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		check_map_bounds(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!check_top_bottom_row(mlx, x))
		return (0);
	else if (!check_left_right_collumns(mlx, y))
		return (0);
	else if (!check_rest(mlx))
		return (0);
	else
		return (1);
}
