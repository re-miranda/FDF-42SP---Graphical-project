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

// static void	free_pointer_string(void **pointer)
// {
// 	void	**swap;

// 	while (pointer)
// 	{
// 		swap = pointer + 1;
// 		if (*pointer)
// 			free(*pointer);
// 		pointer = swap;
// 	}
// }

void	escape(t_mlx *window)
{
	mlx_destroy_window (window->ptr, window->window);
	mlx_destroy_display (window->ptr);
	if (window->ptr)
		free(window->ptr);
	// free_pointer_string((void **)window->map);
	if (window)
		free(window);
	exit (0);
}

void	space(t_mlx *window)
{
	// int	src_axis[2] = {100, 100};
	// int	dest_axis[2] = {400, 400};

	// int	src_axis[2] = {200, 100};
	// int	dest_axis[2] = {300, 400};
	
	// int	src_axis[2] = {200, 400};
	// int	dest_axis[2] = {300, 100};
	
	// int	src_axis[2] = {100, 200};
	// int	dest_axis[2] = {400, 300};
	window->img = init_image(window, 500, 500);
	window->color = rgb_to_int(53, 0, 53);
	draw_map(window);
	// int i = 0;
	// while (i++ < 4)
	// {
	// 	ft_printf("here src_axis[0]:%i\n", src_axis[0]);
	// 	bresenham(src_axis[0], dest_axis[0], src_axis[1], dest_axis[1], window);
	// 	src_axis[0] = src_axis[0] + 50;
	// 	src_axis[1] = src_axis[1] + 50;
	// 	dest_axis[0] = dest_axis[0] - 50;
	// 	dest_axis[1] = dest_axis[1] - 50;
	// }
	mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
	destroy_image(window);
}