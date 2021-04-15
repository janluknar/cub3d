/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:59:45 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:45:05 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_mlx *mlx, double rot)
{
	if (mlx->map->spawn == 'W')
		rot = -ROT;
	mlx->rayc.old_dirx = mlx->rayc.dir_x;
	mlx->rayc.oldplanex = mlx->rayc.planex;
	mlx->rayc.dir_x = mlx->rayc.dir_x * cos(rot) - mlx->rayc.dir_y *
	sin(rot);
	mlx->rayc.dir_y = mlx->rayc.old_dirx * sin(rot) + mlx->rayc.dir_y *
	cos(rot);
	mlx->rayc.planex = mlx->rayc.planex * cos(rot) - mlx->rayc.planey *
	sin(rot);
	mlx->rayc.planey = mlx->rayc.oldplanex * sin(rot) + mlx->rayc.planey *
	cos(rot);
}

void	turn_right(t_mlx *mlx, double rot)
{
	if (mlx->map->spawn != 'W')
		rot = -ROT;
	mlx->rayc.old_dirx = mlx->rayc.dir_x;
	mlx->rayc.oldplanex = mlx->rayc.planex;
	mlx->rayc.dir_x = mlx->rayc.dir_x * cos(rot) - mlx->rayc.dir_y *
	sin(rot);
	mlx->rayc.dir_y = mlx->rayc.old_dirx * sin(rot) + mlx->rayc.dir_y *
	cos(rot);
	mlx->rayc.planex = mlx->rayc.planex * cos(rot) - mlx->rayc.planey *
	sin(rot);
	mlx->rayc.planey = mlx->rayc.oldplanex * sin(rot) + mlx->rayc.planey *
	cos(rot);
}

void	movement(t_mlx *mlx)
{
	double rot;

	rot = ROT;
	if (mlx->mflags.forward_fl || mlx->mflags.backward_fl)
		check_mov_fb(mlx);
	if (mlx->mflags.right_fl || mlx->mflags.left_fl)
	{
		if (mlx->map->spawn == 'W')
			check_mov_lrw(mlx);
		else
			check_mov_lr(mlx);
	}
	if (mlx->mflags.turn_l == 1)
		turn_left(mlx, rot);
	if (mlx->mflags.turn_r == 1)
		turn_right(mlx, rot);
}
