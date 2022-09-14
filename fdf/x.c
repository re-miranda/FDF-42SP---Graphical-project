/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 07:24:18 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/14 09:10:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blue(t_mlx_window *window)
{
	int	color;
	int x;
	int y;

	color = rgb_to_int(0, 53, 53);
	y = 0;
	while (y < window->size_y)
	{
		x = 0;
		while (x < window->size_x)
		{
			pixel_to_image(window, color, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (window->ptr, window->window, window->image->ptr, 0, 0);
}

void	escape(t_mlx_window *window)
{
	mlx_destroy_image (window->ptr, window->image->ptr);
	free(window->image);
	mlx_destroy_window (window->ptr, window->window);
	mlx_destroy_display (window->ptr);
	free(window->ptr);
	free(window);
	exit (0);
}

void	space(t_mlx_window *window)
{
	int src_axis[2] = {0, 0};
	int dest_axis[2] = {500, 300};
	draw_line(src_axis, dest_axis, window);
}
