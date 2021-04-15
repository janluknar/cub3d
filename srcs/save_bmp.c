/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 09:24:14 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 09:45:16 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_image(t_mlx *mlx, int fd)
{
	int y;
	int x;
	int size;

	y = 0;
	size = (mlx->map->width) * (mlx->map->height);
	while (y <= mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			write(fd, &mlx->img.data[size
			- (y * mlx->map->width + mlx->map->width - x)], 4);
			x++;
		}
		y++;
	}
}

void	bmp_header(t_mlx *mlx, int fd)
{
	int header_size;
	int plane;
	int i;

	header_size = 40;
	plane = 1;
	write(fd, &header_size, 4);
	write(fd, &mlx->map->width, 4);
	write(fd, &mlx->map->height, 4);
	write(fd, &plane, 2);
	write(fd, &mlx->img.bpp, 2);
	i = 0;
	while (i++ < 32)
	{
		write(fd, "\0", 1);
	}
}

void	save_bmp(t_mlx *mlx)
{
	int size;
	int	fd;
	int	empty;

	fd = 0;
	size = 0;
	empty = 54;
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	size = 54 + (4 * (mlx->map->width * mlx->map->height));
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &empty, 4);
	bmp_header(mlx, fd);
	bmp_image(mlx, fd);
	close(fd);
	exit(0);
}
