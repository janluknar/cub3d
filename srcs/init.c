/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:24:17 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 12:11:33 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		initalize_velocity(t_mlx *mlx)
{
	if (!(mlx->rayc.sp_order = malloc(sizeof(int) * mlx->map->numsprites)))
		return (-1);
	if (!(mlx->rayc.sp_dist = malloc(sizeof(double) * mlx->map->numsprites)))
		return (-1);
	if (!(mlx->rayc.zbuffer = malloc(sizeof(double) * mlx->map->width)))
		return (-1);
	mlx->mflags.paintmap = 0;
	mlx->mov.speed = SPEED;
	mlx->mov.posx = mlx->map->posx + 0.5;
	mlx->mov.posy = mlx->map->posy + 0.5;
	mlx->mov.posx = mlx->map->posx + 0.5;
	mlx->mov.posy = mlx->map->posy;
	return (1);
}

int		initalize_variables(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!(mlx->map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	mlx->map->numsprites = 0;
	mlx->map->mapstr = NULL;
	mlx->map->info_count = 0;
	mlx->map->invalmap_flag = 0;
	mlx->map->spawnflag = 0;
	return (1);
}

int		initalize_map(t_mlx *mlx, char **argv)
{
	if (read_cub_file(mlx->map, argv[1]) == -1)
	{
		ft_printf("This map does not exist\n");
		return (0);
	}
	if (mlx->map->invalmap_flag || !mlx->map->spawnflag)
	{
		ft_printf("Map error\n");
		return (0);
	}
	check_res(mlx);
	if (!check_map_bounds(mlx))
	{
		ft_printf("Map error\n");
		return (0);
	}
	return (1);
}

int		initalize_sprites(t_mlx *mlx, int argc, char **argv)
{
	if (!(load_textures(mlx)))
	{
		ft_printf("Error loading textures\n");
		return (0);
	}
	mlx->map->save_flag = 0;
	if (argc == 3)
	{
		if (!(ft_strcmp(argv[2], "--save")))
			mlx->map->save_flag = 1;
	}
	return (1);
}
