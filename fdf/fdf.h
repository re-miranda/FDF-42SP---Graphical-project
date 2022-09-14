/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/14 09:11:39 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_gnl_printf.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_mlx_image
{
	void	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}	t_mlx_image;

typedef struct s_mlx_window
{
	void		*ptr;
	void		*window;
	int			size_x;
	int			size_y;
	t_mlx_image	*image;
}	t_mlx_window;

// X
void			blue(t_mlx_window *window);
void			escape(t_mlx_window *window);
void			space(t_mlx_window *window);

// LINE_HANDLER
int				trace_line(int src_axis[2], int *d, int delta[2], int dest_axis[2]);
void			draw_line(int src_axis[2], int dest_axis[2], t_mlx_window *window);

// INIT_MLX
t_mlx_image		*init_image(t_mlx_window *window);
t_mlx_window	*init_window(int size_x, int size_y, char *window_title);

// IMAGE_UTILS
int				rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);
void			pixel_to_image(t_mlx_window *window, int color, int x, int y);
int				*get_pixel_addr(t_mlx_window *window, int x, int y);

// INPUT_UTILS
int				action_hook(int keycode, t_mlx_window *window);
void			init_input(t_mlx_window *window);

#endif