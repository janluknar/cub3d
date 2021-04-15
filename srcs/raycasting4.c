/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:27:38 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 09:09:54 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_sprite(t_mlx *mlx, int y, int stripes)
{
	int d;

	while (y < mlx->rayc.drawend_y)
	{
		d = (y - mlx->rayc.v_movescreen)
		* 256 - mlx->map->height * 128 + mlx->rayc.sp_height * 128;
		mlx->tex[4].tex_y = ((d * mlx->tex[4].height) /
		mlx->rayc.sp_height) / 256;
		mlx->tex[4].tex_y = (y - (-mlx->rayc.sp_height / 2 +
		mlx->map->height / 2)) / (mlx->rayc.sp_height
		/ (double)mlx->tex[4].height);
		mlx->tex[4].color =
		mlx->tex[4].data[mlx->tex[4].tex_x +
		(mlx->tex[4].width) * mlx->tex[4].tex_y];
		ray_sp(mlx, y, stripes, mlx->tex[4].color);
		y++;
	}
}

void	paint_sprites(t_mlx *mlx)
{
	int stripes;
	int y;

	stripes = mlx->rayc.drawstart_x;
	while (stripes < mlx->rayc.drawend_x)
	{
		y = mlx->rayc.drawstart_y;
		mlx->tex[4].tex_x = (int)(256 * (stripes -
		(-mlx->rayc.sp_width / 2 + mlx->rayc.sp_screenx))
		* mlx->tex[4].width / mlx->rayc.sp_width) / 256;
		if (mlx->rayc.transformy > 0 && stripes > 0 &&
		stripes < mlx->map->width &&
		mlx->rayc.transformy < mlx->rayc.zbuffer[stripes])
			paint_sprite(mlx, y, stripes);
		stripes++;
	}
}

void	init_west(t_mlx *mlx)
{
	if (mlx->map->spawn == 'W')
	{
		mlx->rayc.planex = 0;
		mlx->rayc.planey = -0.66;
		mlx->rayc.dir_x = 1;
		mlx->rayc.dir_y = 0;
	}
}
