/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:39:05 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 02:31:04 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx_img	*init_image(t_mlx *mlx, int size_x, int size_y)
{
	t_mlx_img	*image;

	image = malloc(sizeof(t_mlx_img));
	if (!image)
		escape(mlx);
	image->ptr = mlx_new_image(mlx->ptr, size_x, size_y);
	if (!image->ptr)
		escape(mlx);
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_per_pixel, \
		&image->size_line, &image->endian);
	return (image);
}

void	destroy_image(t_mlx *mlx)
{
	mlx_destroy_image (mlx->ptr, mlx->img->ptr);
	if (mlx->img)
		free(mlx->img);
}

t_mlx	*init_mlx(int size_x, int size_y, char *window_title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->window = mlx_new_window(mlx->ptr, size_x, size_y, window_title);
	if (!mlx->window)
	{
		mlx_destroy_display (mlx->ptr);
		free (mlx->ptr);
		free(mlx);
		return (NULL);
	}
	mlx->size_x = size_x;
	mlx->size_y = size_y;
	mlx->map = NULL;
	return (mlx);
}
