/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:24 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:45:27 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	facing_init(t_mlx *mlx)
{
	if (mlx->map->spawn == 'N')
	{
		mlx->rayc.planex = 0.5;
		mlx->rayc.planey = 0;
		mlx->rayc.dir_x = 0;
		mlx->rayc.dir_y = -1;
	}
	if (mlx->map->spawn == 'S')
	{
		mlx->rayc.planex = -0.5;
		mlx->rayc.planey = 0;
		mlx->rayc.dir_x = 0;
		mlx->rayc.dir_y = 1;
	}
	if (mlx->map->spawn == 'E')
	{
		mlx->rayc.planex = 0;
		mlx->rayc.planey = 0.66;
		mlx->rayc.dir_x = 1;
		mlx->rayc.dir_y = 0;
	}
	init_west(mlx);
}

void	ray_sp(t_mlx *mlx, int y, int x, int color)
{
	if (color != BLACK)
		mlx->img.data[y * mlx->map->width + x] = color;
}

void	paint_rays(t_mlx *mlx, int x, int drawstart, int drawend)
{
	int h;

	h = 0;
	while (h < drawstart)
	{
		ray(mlx, h, x, mlx->map->ceiling);
		h++;
	}
	while (h < drawend)
	{
		paint_walls(mlx, h, x);
		h++;
	}
	while (h < mlx->map->height)
	{
		ray(mlx, h, x, mlx->map->floor);
		h++;
	}
}

int		choose_tex(t_mlx *mlx)
{
	if (mlx->rayc.side == 0 && mlx->rayc.raydir_x > 0)
		return (3);
	else if (mlx->rayc.side == 0 && mlx->rayc.raydir_x < 0)
		return (2);
	else if (mlx->rayc.side == 1 && mlx->rayc.raydir_y > 0)
		return (1);
	else if (mlx->rayc.side == 1 && mlx->rayc.raydir_y < 0)
		return (0);
}

int		raycaster(t_mlx *mlx)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	raycasting(mlx, x);
	spritecasting(mlx, i);
	return (0);
}
