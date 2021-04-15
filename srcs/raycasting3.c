/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:04:48 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/01 13:40:48 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_walls(t_mlx *mlx, int h, int x)
{
	mlx->tex[mlx->rayc.texnum].tex_y = (h - (-mlx->rayc.lineheight / 2 +
	mlx->map->height / 2)) / (mlx->rayc.lineheight
	/ (double)mlx->tex[mlx->rayc.texnum].height);
	mlx->tex[mlx->rayc.texnum].color =
	mlx->tex[mlx->rayc.texnum].data[mlx->tex[mlx->rayc.texnum].tex_x +
	(mlx->tex[mlx->rayc.texnum].width) * mlx->tex[mlx->rayc.texnum].tex_y];
	if (mlx->rayc.side == 1)
		mlx->tex[mlx->rayc.texnum].color =
		(mlx->tex[mlx->rayc.texnum].color >> 1) & 8355711;
	ray(mlx, h, x, mlx->tex[mlx->rayc.texnum].color);
}

void	raycasting(t_mlx *mlx, int x)
{
	while (x < mlx->map->width)
	{
		init_variables(mlx, x);
		init_variables2(mlx);
		perform_dda(mlx);
		calc_draw_sections(mlx);
		mlx->rayc.texnum = choose_tex(mlx);
		texture_calc(mlx);
		paint_rays(mlx, x, mlx->rayc.drawstart, mlx->rayc.drawend);
		mlx->rayc.zbuffer[x] = mlx->rayc.perpwalldist;
		x++;
	}
}

void	sprite_calc(t_mlx *mlx, int i)
{
	mlx->rayc.sp_x = mlx->rayc.sprites[mlx->rayc.sp_order[i]].x
	- mlx->mov.posx;
	mlx->rayc.sp_y = mlx->rayc.sprites[mlx->rayc.sp_order[i]].y
	- mlx->mov.posy;
	mlx->rayc.invdet = 1.0 / (mlx->rayc.planex *
	mlx->rayc.dir_y - mlx->rayc.dir_x * mlx->rayc.planey);
	mlx->rayc.transformx = mlx->rayc.invdet *
	(mlx->rayc.dir_y * mlx->rayc.sp_x -
	mlx->rayc.dir_x * mlx->rayc.sp_y);
	mlx->rayc.transformy = mlx->rayc.invdet *
	(-mlx->rayc.planey * mlx->rayc.sp_x +
	mlx->rayc.planex * mlx->rayc.sp_y);
	mlx->rayc.sp_screenx = (int)(mlx->map->width / 2)
	* (1 + mlx->rayc.transformx / mlx->rayc.transformy);
	mlx->rayc.v_movescreen = (int)(0.0 / mlx->rayc.transformy);
	mlx->rayc.sp_height = abs((int)(mlx->map->height /
	mlx->rayc.transformy)) / 1;
	mlx->rayc.drawstart_y = -mlx->rayc.sp_height / 2 +
	mlx->map->height / 2 + mlx->rayc.v_movescreen;
	if (mlx->rayc.drawstart_y < 0)
		mlx->rayc.drawstart_y = 0;
	mlx->rayc.drawend_y = mlx->rayc.sp_height / 2 +
	mlx->map->height / 2 + mlx->rayc.v_movescreen;
}

void	sprite_calc2(t_mlx *mlx)
{
	if (mlx->rayc.drawend_y >= mlx->map->height)
		mlx->rayc.drawend_y = mlx->map->height - 1;
	mlx->rayc.sp_width = abs((int)(mlx->map->height
	/ (mlx->rayc.transformy))) / 1;
	mlx->rayc.drawstart_x = -mlx->rayc.sp_width
	/ 2 + mlx->rayc.sp_screenx;
	if (mlx->rayc.drawstart_x < 0)
		mlx->rayc.drawstart_x = 0;
	mlx->rayc.drawend_x = mlx->rayc.sp_width / 2 + mlx->rayc.sp_screenx;
	if (mlx->rayc.drawend_x >= mlx->map->width)
		mlx->rayc.drawend_x = mlx->map->width - 1;
}

void	spritecasting(t_mlx *mlx, int i)
{
	while (i < mlx->map->numsprites)
	{
		mlx->rayc.sp_order[i] = i;
		mlx->rayc.sp_dist[i] = ((mlx->mov.posx - mlx->rayc.sprites[i].x) *
		(mlx->mov.posx - mlx->rayc.sprites[i].x) +
		(mlx->mov.posy - mlx->rayc.sprites[i].y) *
		(mlx->mov.posy - mlx->rayc.sprites[i].y));
		i++;
	}
	sort_sprites(mlx);
	i = 0;
	while (i < mlx->map->numsprites)
	{
		sprite_calc(mlx, i);
		sprite_calc2(mlx);
		paint_sprites(mlx);
		i++;
	}
}
