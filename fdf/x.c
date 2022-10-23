/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 07:24:18 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:34:19 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blue(t_mlx *window)
{
	int	color;
	int	x;
	int	y;

	window->img = init_image(window, 500, 500);
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
	mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
	destroy_image(window);
}

static void	free_map(t_mlx *window)
{
	int i;

	i = window->map_size_y;
	while (i--)
		free(window->map[i]);
	free(window->map);
}

void	escape(t_mlx *window)
{
	mlx_destroy_window (window->ptr, window->window);
	mlx_destroy_display (window->ptr);
	if (window->ptr)
		free(window->ptr);
	// free_pointer_string((void **)window->map);
	free_map(window);
	if (window)
		free(window);
	exit (0);
}

void	space(t_mlx *window)
{
	window->img = init_image(window, 500, 500);
	window->color = rgb_to_int(255, 255, 255);
	draw_map(window);
	mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
	destroy_image(window);
}