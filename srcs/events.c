/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:03:59 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 12:14:15 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->mflags.forward_fl = 1;
	if (key == KEY_A)
		mlx->mflags.left_fl = 1;
	if (key == KEY_S)
		mlx->mflags.backward_fl = 1;
	if (key == KEY_D)
		mlx->mflags.right_fl = 1;
	if (key == KEY_LEFT)
		mlx->mflags.turn_l = 1;
	if (key == KEY_RIGHT)
		mlx->mflags.turn_r = 1;
	if (key == KEY_Q)
	{
		if (mlx->mflags.paintmap == 0)
			mlx->mflags.paintmap = 1;
		else
			mlx->mflags.paintmap = 0;
	}
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->mflags.forward_fl = 0;
	if (key == KEY_A)
		mlx->mflags.left_fl = 0;
	if (key == KEY_S)
		mlx->mflags.backward_fl = 0;
	if (key == KEY_D)
		mlx->mflags.right_fl = 0;
	if (key == KEY_LEFT)
		mlx->mflags.turn_l = 0;
	if (key == KEY_RIGHT)
		mlx->mflags.turn_r = 0;
	return (0);
}

int		exit_game(void)
{
	exit(0);
	return (0);
}
