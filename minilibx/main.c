/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:11:43 by jluknar-          #+#    #+#             */
/*   Updated: 2020/02/04 18:51:25 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	void *mlx;
	void *win;
}t_test;

int rgb_int(int red, int green, int blue)
{
    int rgb;
    rgb = red;
    rgb = (rgb << 8) + green;
    rgb = (rgb << 8) + blue;
    return (rgb);
}

int	pilla_tecla(int key, t_test *t)
{
	printf("%d\n", key);
	if (key == 53)
    {
        printf("kill task\n");
        mlx_destroy_window(t->mlx, t->win);
        exit(0);
    }
	if (key == 1)
		printf("click izquierdo\n");
	if (key == 2)
		printf("click derecho\n");
    return (0);
}


int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	t_test *t = NULL;
	int		x;
	int		y = 0;
	
	t = (t_test*)malloc(sizeof(t_test));
	mlx = mlx_init();
	t->mlx = mlx;

	img = mlx_new_image (mlx, 50, 50);

	win = mlx_new_window (mlx, 500, 400, "half life 50");
	t->win = win;
	while (y < 51)
	{
		mlx_pixel_put (t->mlx, t->win, x, y, rgb_int(255, 255, 255));
		x = 0;
		while (x < 51)
		{
			mlx_pixel_put (t->mlx, t->win, x, y, rgb_int(255, 255, 255));
			x++;
		}
		y++;
	}

	mlx_hook (win, 2, 0, pilla_tecla, t);
	mlx_mouse_hook (win, pilla_tecla, t);

	mlx_string_put (mlx, win, 50, 50, rgb_int(100, 87, 32), "gay gay gay gay gay gay gay gay gay");

	mlx_loop(mlx);
	return (0);
}
