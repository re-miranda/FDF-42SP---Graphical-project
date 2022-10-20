/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 04:18:19 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/18 07:53:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	*get_pixel_addr(t_mlx *window, int x, int y)
{
	unsigned int	offset_bytes;

	if (x > window->size_x || y > window->size_y)
		return (NULL);
	if (x < 0 || y < 0)
		return (NULL);
	offset_bytes = x * window->img->bits_per_pixel / 8;
	offset_bytes += y * window->img->size_line;
	return (int *)(window->img->addr + offset_bytes);
}

int	rgb_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
	int				color;
	unsigned char	*color_ptr;

	color_ptr = (unsigned char *)&color;
	color_ptr[0] = blue;
	color_ptr[1] = green;
	color_ptr[2] = red;
	color_ptr[3] = 0;
	return (color);
}

void	pixel_to_image(t_mlx *window, int color, int x, int y)
{
	int	*pixel_addr;

	pixel_addr = get_pixel_addr(window, x, y);
	if (pixel_addr)
		*pixel_addr = color;
}
