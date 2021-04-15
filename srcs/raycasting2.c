/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:37:44 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/01 13:35:56 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables(t_mlx *mlx, int x)
{
	mlx->rayc.camerax = 2 * x / (double)mlx->map->width - 1;
	mlx->rayc.raydir_x = mlx->rayc.dir_x + mlx->rayc.planex *
	mlx->rayc.camerax;
	mlx->rayc.raydir_y = mlx->rayc.dir_y + mlx->rayc.planey *
	mlx->rayc.camerax;
	mlx->rayc.mapx = (int)mlx->mov.posx;
	mlx->rayc.mapy = (int)mlx->mov.posy;
	mlx->rayc.deltadistx = fabs(1 / mlx->rayc.raydir_x);
	mlx->rayc.deltadisty = fabs(1 / mlx->rayc.raydir_y);
	mlx->rayc.hit = 0;
}

void	init_variables2(t_mlx *mlx)
{
	if (mlx->rayc.raydir_x < 0)
	{
		mlx->rayc.stepx = -1;
		mlx->rayc.sidedistx = (mlx->mov.posx - mlx->rayc.mapx)
		* mlx->rayc.deltadistx;
	}
	else
	{
		mlx->rayc.stepx = 1;
		mlx->rayc.sidedistx = (mlx->rayc.mapx + 1.0 - mlx->mov.posx)
		* mlx->rayc.deltadistx;
	}
	if (mlx->rayc.raydir_y < 0)
	{
		mlx->rayc.stepy = -1;
		mlx->rayc.sidedisty = (mlx->mov.posy - mlx->rayc.mapy)
		* mlx->rayc.deltadisty;
	}
	else
	{
		mlx->rayc.stepy = 1;
		mlx->rayc.sidedisty = (mlx->rayc.mapy + 1.0 - mlx->mov.posy)
		* mlx->rayc.deltadisty;
	}
}

void	perform_dda(t_mlx *mlx)
{
	while (mlx->rayc.hit == 0)
	{
		if (mlx->rayc.sidedistx < mlx->rayc.sidedisty)
		{
			mlx->rayc.sidedistx += mlx->rayc.deltadistx;
			mlx->rayc.mapx += mlx->rayc.stepx;
			mlx->rayc.side = 0;
		}
		else
		{
			mlx->rayc.sidedisty += mlx->rayc.deltadisty;
			mlx->rayc.mapy += mlx->rayc.stepy;
			mlx->rayc.side = 1;
		}
		if (mlx->map->maparray[mlx->rayc.mapy][mlx->rayc.mapx] == 1)
			mlx->rayc.hit = 1;
		if (mlx->rayc.side == 0)
			mlx->rayc.perpwalldist = (mlx->rayc.mapx - mlx->mov.posx +
			(1 - mlx->rayc.stepx) / 2) / mlx->rayc.raydir_x;
		else
			mlx->rayc.perpwalldist = (mlx->rayc.mapy - mlx->mov.posy +
			(1 - mlx->rayc.stepy) / 2) / mlx->rayc.raydir_y;
	}
}

void	calc_draw_sections(t_mlx *mlx)
{
	mlx->rayc.lineheight = (int)(mlx->map->height / mlx->rayc.perpwalldist);
	mlx->rayc.drawstart = -mlx->rayc.lineheight / 2 + mlx->map->height / 2;
	if (mlx->rayc.drawstart < 0)
		mlx->rayc.drawstart = 0;
	mlx->rayc.drawend = mlx->rayc.lineheight / 2 + mlx->map->height / 2;
	if (mlx->rayc.drawend >= mlx->map->height)
		mlx->rayc.drawend = mlx->map->height - 1;
}

void	texture_calc(t_mlx *mlx)
{
	if (mlx->rayc.side == 0)
		mlx->tex[mlx->rayc.texnum].wallx = mlx->mov.posy +
		mlx->rayc.perpwalldist * mlx->rayc.raydir_y;
	else
		mlx->tex[mlx->rayc.texnum].wallx = mlx->mov.posx +
		mlx->rayc.perpwalldist * mlx->rayc.raydir_x;
	mlx->tex[mlx->rayc.texnum].wallx -=
	floor((mlx->tex[mlx->rayc.texnum].wallx));
	mlx->tex[mlx->rayc.texnum].tex_x = mlx->tex[mlx->rayc.texnum].wallx *
	(double)mlx->tex[mlx->rayc.texnum].width;
	if (mlx->rayc.side == 0 && mlx->rayc.raydir_x > 0)
		mlx->tex[mlx->rayc.texnum].tex_x = mlx->tex[mlx->rayc.texnum].width -
		mlx->tex[mlx->rayc.texnum].tex_x - 1;
	if (mlx->rayc.side == 1 && mlx->rayc.raydir_y < 0)
		mlx->tex[mlx->rayc.texnum].tex_x = mlx->tex[mlx->rayc.texnum].width -
		mlx->tex[mlx->rayc.texnum].tex_x - 1;
	mlx->tex[mlx->rayc.texnum].step = 1.0 * mlx->tex[mlx->rayc.texnum].height /
	mlx->rayc.lineheight;
	mlx->tex[mlx->rayc.texnum].texpos = (mlx->rayc.drawstart - mlx->map->height
	/ 2 + mlx->rayc.lineheight / 2) * mlx->tex[mlx->rayc.texnum].step;
}
