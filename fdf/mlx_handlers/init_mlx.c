/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:39:05 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/22 05:24:14 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx_img	*init_image(t_mlx *window, int size_x, int size_y)
{
	t_mlx_img	*image;

	image = malloc(sizeof(t_mlx_img));
	if (!image)
		escape(window);
	image->ptr = mlx_new_image(window->ptr, size_x, size_y);
	if (!image->ptr)
		escape(window);
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_per_pixel, \
		&image->size_line, &image->endian);
	return (image);
}

void	destroy_image(t_mlx *window)
{
	mlx_destroy_image (window->ptr, window->img->ptr);
	if (window->img)
		free(window->img);
}

t_mlx	*init_mlx(int size_x, int size_y, char *window_title)
{
	t_mlx	*window;

	window = malloc(sizeof(t_mlx));
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
	window->map = NULL;
	return (window);
}
