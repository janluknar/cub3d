/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:15:31 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/01 13:20:31 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		numlen(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	ray(t_mlx *mlx, int y, int x, int color)
{
	mlx->img.data[y * mlx->map->width + x] = color;
}
