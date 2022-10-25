/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:55:32 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 02:35:55 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_map(t_mlx *mlx)
{
	mlx->img = init_image(mlx, 500, 500);
	mlx->color = rgb_to_int(255, 255, 255);
	draw_map(mlx);
	mlx_put_image_to_window (mlx->ptr, mlx->window, mlx->img->ptr, 0, 0);
	destroy_image(mlx);
}

void	put_blue_screen(t_mlx *mlx)
{
	int	color;
	int	x;
	int	y;

	mlx->img = init_image(mlx, 500, 500);
	color = rgb_to_int(0, 53, 53);
	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			pixel_to_image(mlx, color, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (mlx->ptr, mlx->window, mlx->img->ptr, 0, 0);
	destroy_image(mlx);
}
