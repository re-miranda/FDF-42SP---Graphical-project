/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 04:18:19 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/26 11:24:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	*get_pixel_addr(t_mlx *mlx, int x, int y)
{
	unsigned int	offset_bytes;

	if (x > mlx->size_x || y > mlx->size_y)
		return (NULL);
	if (x < 0 || y < 0)
		return (NULL);
	offset_bytes = x * mlx->img->bits_per_pixel / 8;
	offset_bytes += y * mlx->img->size_line;
	return ((int *)(mlx->img->addr + offset_bytes));
}

void	pixel_to_image(t_mlx *mlx, int color, int x, int y)
{
	int	*pixel_addr;

	pixel_addr = get_pixel_addr(mlx, x, y);
	if (pixel_addr)
		*pixel_addr = color;
}

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	int				color;
	unsigned char	*color_ptr;

	color_ptr = (unsigned char *)&color;
	color_ptr[0] = b;
	color_ptr[1] = g;
	color_ptr[2] = r;
	color_ptr[3] = 0;
	return (color);
}
