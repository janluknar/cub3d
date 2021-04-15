/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:39:40 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:19:33 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_mlx *mlx)
{
	int i;

	if (!(mlx->tex[0].ptr = mlx_xpm_file_to_image(mlx->ptr,
mlx->map->north, &mlx->tex[0].width, &mlx->tex[0].height)))
		return (0);
	if (!(mlx->tex[1].ptr = mlx_xpm_file_to_image(mlx->ptr,
mlx->map->south, &mlx->tex[1].width, &mlx->tex[1].height)))
		return (0);
	if (!(mlx->tex[2].ptr = mlx_xpm_file_to_image(mlx->ptr,
mlx->map->west, &mlx->tex[2].width, &mlx->tex[2].height)))
		return (0);
	if (!(mlx->tex[3].ptr = mlx_xpm_file_to_image(mlx->ptr,
mlx->map->east, &mlx->tex[3].width, &mlx->tex[3].height)))
		return (0);
	if (!(mlx->tex[4].ptr = mlx_xpm_file_to_image(mlx->ptr,
mlx->map->sprite, &mlx->tex[4].width, &mlx->tex[4].height)))
		return (0);
	i = 0;
	while (i < TEXTURES)
	{
		mlx->tex[i].data = (int*)mlx_get_data_addr(mlx->tex[i].ptr,
	&mlx->tex[i].bpp, &mlx->tex[i].size, &mlx->tex[i].endian);
		i++;
	}
	return (1);
}
