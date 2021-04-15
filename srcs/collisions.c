/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:56:39 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:44:32 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_mov_fb(t_mlx *mlx)
{
	if (mlx->mflags.forward_fl &&
	(mlx->mov.sum_x = mlx->mov.posx + mlx->rayc.dir_x * mlx->mov.speed * 3))
		mlx->mov.sum_y = mlx->mov.posy + mlx->rayc.dir_y * mlx->mov.speed *
		3;
	if (mlx->mflags.backward_fl &&
	(mlx->mov.sum_x = mlx->mov.posx - mlx->rayc.dir_x * mlx->mov.speed * 3))
		mlx->mov.sum_y = mlx->mov.posy - mlx->rayc.dir_y * mlx->mov.speed *
		3;
	if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0
	&& mlx->mflags.forward_fl)
		mlx->mov.posx += mlx->rayc.dir_x * mlx->mov.speed;
	if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0
	&& mlx->mflags.forward_fl)
		mlx->mov.posy += mlx->rayc.dir_y * mlx->mov.speed;
	if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0
	&& mlx->mflags.backward_fl)
		mlx->mov.posx -= mlx->rayc.dir_x * mlx->mov.speed;
	if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0
	&& mlx->mflags.backward_fl)
		mlx->mov.posy -= mlx->rayc.dir_y * mlx->mov.speed;
	mlx->mov.sum_x = 0;
	mlx->mov.sum_y = 0;
}

void	check_mov_lr(t_mlx *mlx)
{
	if (mlx->mflags.right_fl)
	{
		mlx->mov.sum_x = mlx->mov.posx - mlx->rayc.dir_y * mlx->mov.speed * 3;
		mlx->mov.sum_y = mlx->mov.posy + mlx->rayc.dir_x * mlx->mov.speed * 3;
		if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0)
			mlx->mov.posx -= mlx->rayc.dir_y * mlx->mov.speed / 1.5;
		if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0)
			mlx->mov.posy += mlx->rayc.dir_x * mlx->mov.speed / 1.5;
	}
	if (mlx->mflags.left_fl)
	{
		mlx->mov.sum_x = mlx->mov.posx + mlx->rayc.dir_y * mlx->mov.speed * 3;
		mlx->mov.sum_y = mlx->mov.posy - mlx->rayc.dir_x * mlx->mov.speed * 3;
		if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0)
			mlx->mov.posx += mlx->rayc.dir_y * mlx->mov.speed / 1.5;
		if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0)
			mlx->mov.posy -= mlx->rayc.dir_x * mlx->mov.speed / 1.5;
	}
	mlx->mov.sum_x = 0;
	mlx->mov.sum_y = 0;
}

void	check_mov_lrw(t_mlx *mlx)
{
	if (mlx->mflags.left_fl)
	{
		mlx->mov.sum_x = mlx->mov.posx - mlx->rayc.dir_y * mlx->mov.speed * 3;
		mlx->mov.sum_y = mlx->mov.posy + mlx->rayc.dir_x * mlx->mov.speed * 3;
		if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0)
			mlx->mov.posx -= mlx->rayc.dir_y * mlx->mov.speed / 1.5;
		if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0)
			mlx->mov.posy += mlx->rayc.dir_x * mlx->mov.speed / 1.5;
	}
	if (mlx->mflags.right_fl)
	{
		mlx->mov.sum_x = mlx->mov.posx + mlx->rayc.dir_y * mlx->mov.speed * 3;
		mlx->mov.sum_y = mlx->mov.posy - mlx->rayc.dir_x * mlx->mov.speed * 3;
		if (mlx->map->maparray[(int)mlx->mov.posy][(int)mlx->mov.sum_x] == 0)
			mlx->mov.posx += mlx->rayc.dir_y * mlx->mov.speed / 1.5;
		if (mlx->map->maparray[(int)mlx->mov.sum_y][(int)mlx->mov.posx] == 0)
			mlx->mov.posy -= mlx->rayc.dir_x * mlx->mov.speed / 1.5;
	}
	mlx->mov.sum_x = 0;
	mlx->mov.sum_y = 0;
}
