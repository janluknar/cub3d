/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:49:38 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 09:42:44 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_pos(t_mlx *mlx, int x, int y, int sprite)
{
	mlx->rayc.sprites[sprite].x = x + 0.5;
	mlx->rayc.sprites[sprite].y = y + 0.5;
	mlx->rayc.sprites[sprite].tex = 4;
	mlx->rayc.sprites[sprite].dist = 0.0;
}

int		get_sprite_data(t_mlx *mlx)
{
	int x;
	int y;
	int sprite;

	if (!(mlx->rayc.sprites = malloc(sizeof(t_sp) * mlx->map->numsprites)))
		return (0);
	y = 0;
	sprite = 0;
	while (y < mlx->map->rows)
	{
		x = 0;
		while (x < mlx->map->collumns)
		{
			if (mlx->map->maparray[y][x] == 2)
			{
				set_sprite_pos(mlx, x, y, sprite);
				sprite++;
			}
			x++;
		}
		y++;
	}
}

void	sort_sprites(t_mlx *mlx)
{
	int		i;
	int		j;
	int		aux_order;
	double	aux_dist;

	i = 0;
	while (i < mlx->map->numsprites - 1)
	{
		j = 0;
		while (j < mlx->map->numsprites - 1)
		{
			if (mlx->rayc.sp_dist[j] < mlx->rayc.sp_dist[j + 1])
			{
				aux_dist = mlx->rayc.sp_dist[j];
				mlx->rayc.sp_dist[j] = mlx->rayc.sp_dist[j + 1];
				mlx->rayc.sp_dist[j + 1] = aux_dist;
				aux_order = mlx->rayc.sp_order[j];
				mlx->rayc.sp_order[j] = mlx->rayc.sp_order[j + 1];
				mlx->rayc.sp_order[j + 1] = aux_order;
			}
			j++;
		}
		i++;
	}
}
