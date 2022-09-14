/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:39:05 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/14 05:41:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx_image	*init_image(t_mlx_window *window)
{
	t_mlx_image	*image;

	image = malloc(sizeof(t_mlx_image));
	if (!image)
		return (NULL);
	image->ptr = mlx_new_image(window->ptr, window->size_x, window->size_y);
	if (!image->ptr)
	{
		free(image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_per_pixel, \
		&image->size_line, &image->endian);
	return (image);
}

t_mlx_window	*init_window(int size_x, int size_y, char *window_title)
{
	t_mlx_window	*window;

	window = malloc(sizeof(t_mlx_window));
	if (!window)
		return (NULL);
	window->ptr = mlx_init();
	if (!window->ptr)
	{
		free(window);
		return (NULL);
	}
	window->window = mlx_new_window(window->ptr, size_x, size_y, window_title);
	if (!window->window)
	{
		mlx_destroy_display (window->ptr);
		free (window->ptr);
		free(window);
		return (NULL);
	}
	window->size_x = size_x;
	window->size_y = size_y;
	return (window);
}
