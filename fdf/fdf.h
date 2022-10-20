/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:28:28 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_gnl_printf.h"
# include "mlx.h"
# include <X11/keysym.h>
# include "map_utils/map_utils.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
}	t_map;

typedef struct s_mlx_img
{
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}	t_mlx_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		size_x;
	int		size_y;
	t_mlx_img	*img;
	t_map	**map;
	int		map_size_x;
	int		map_size_y;
	int		color;
}	t_mlx;

// X
void	blue(t_mlx *window);
void	escape(t_mlx *window);
void	space(t_mlx *window);

// LINE_HANDLER
void	bresenham(int x0, int y0, int x1, int y1, t_mlx *window);
void	draw_map(t_mlx *window);

// INIT_MLX
t_mlx_img		*init_image(t_mlx *window, int size_x, int size_y);
void		destroy_image(t_mlx *window);
t_mlx	*init_mlx(int size_x, int size_y, char *window_title);

// IMAGE_UTILS
int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);
void	pixel_to_image(t_mlx *window, int color, int x, int y);
int		*get_pixel_addr(t_mlx *window, int x, int y);
void	x_invert_int_matrix(int *matrix, int width, int height);
void	y_invert_int_matrix(int *matrix, int width, int height);

// INPUT_UTILS
int		action_hook(int keycode, t_mlx *window);
void	init_input(t_mlx *window);

// MAP_UTILS
int	get_map(char *path, t_mlx *window);

// GENERAL_UTILS
void	int_swap(int *a, int *b);
void	pointer_swap(void **a, void **b);
int		ptrstrlen(t_map	**ptr);
int		mapstrlen(t_map	*ptr);

#endif