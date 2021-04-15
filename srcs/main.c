/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:49 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/06 08:59:39 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map_square(int x, int y, t_mlx *mlx, int color)
{
	int	height;
	int	width;

	height = 0;
	while (height < 10)
	{
		width = 0;
		while (width < 10)
		{
			mlx->img.data[((height) + y) *
			mlx->map->width + ((width) + -x)] = color;
			width++;
		}
		height++;
	}
}

void	paint_map(int x, int y, t_mlx *mlx, int scale)
{
	int rows;
	int reset;

	reset = x;
	rows = 0;
	while (rows < mlx->map->rows)
	{
		mlx->map->col = 0;
		x = reset;
		while (mlx->map->col < mlx->map->collumns)
		{
			if (mlx->map->maparray[rows][mlx->map->col] == 1)
				draw_map_square(x, y, mlx, WHITE);
			else if (mlx->map->maparray[rows][mlx->map->col] == 0)
				draw_map_square(x, y, mlx, BLACK);
			else if (mlx->map->maparray[rows][mlx->map->col] == 3)
				draw_map_square(x, y, mlx, BLACK);
			else
				draw_map_square(x, y, mlx, LIME);
			mlx->map->col++;
			x -= scale;
		}
		y += scale;
		rows++;
	}
}

void	paint_pos(t_mlx *mlx, int scale)
{
	draw_map_square(-mlx->mov.posx * scale * 2,
	mlx->mov.posy * scale * 2, mlx, RED);
}

int		paint_everything(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, mlx->map->width,
	mlx->map->height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
	&mlx->img.size_line, &mlx->img.endian);
	movement(mlx);
	raycaster(mlx);
	if (mlx->mflags.paintmap == 1)
	{
		paint_map(0, 0, mlx, 10);
		paint_pos(mlx, 5);
	}
	if (mlx->map->save_flag)
		save_bmp(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
	{
		ft_printf("The second argument must be a path for the map\n");
		return (0);
	}
	initalize_variables(&mlx);
	if (!(initalize_map(&mlx, argv)))
		return (0);
	get_sprite_data(&mlx);
	initalize_velocity(&mlx);
	facing_init(&mlx);
	if (!(initalize_sprites(&mlx, argc, argv)))
		return (0);
	mlx.win = mlx_new_window(mlx.ptr, mlx.map->width, mlx.map->height, "cub3d");
	mlx_hook(mlx.win, 2, 0, &key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, &key_release, &mlx);
	mlx_hook(mlx.win, 17, 0, &exit_game, &mlx);
	mlx_loop_hook(mlx.ptr, &paint_everything, &mlx);
	mlx_loop(mlx.ptr);
	free(mlx.map);
	return (0);
}
