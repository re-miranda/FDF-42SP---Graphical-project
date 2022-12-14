/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/28 11:34:08 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_gnl_printf.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_bresen
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresen;

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
	void		*ptr;
	void		*window;
	int			size_x;
	int			size_y;
	t_mlx_img	*img;
	t_map		**map;
	int			map_size_x;
	int			map_size_y;
	int			color;
	int			global_multiplier;
}	t_mlx;

// MLX_INIT
t_mlx_img	*init_image(t_mlx *mlx, int size_x, int size_y);
void		destroy_image(t_mlx *mlx);
t_mlx		*init_mlx(int size_x, int size_y, char *window_title);
// MLX_INPUT
int			action_hook(int keycode, t_mlx *mlx);
void		init_input(t_mlx *mlx);
// MLX_PIXEL_TOOLS
int			rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
void		pixel_to_image(t_mlx *mlx, int color, int x, int y);

// BRESENHAM_LINE
void		bresenham(t_bresen *line, t_mlx *mlx);
// MAP_DRAW
void		draw_map(t_mlx *mlx);
// PUT_TO_SCREEN
int			put_map(t_mlx *mlx);
void		put_blue_screen(t_mlx *mlx);

// MAP_CENTRALIZE
void		map_centralize(t_mlx *mlx);
// MAP_ISOMETRIC
void		isometric_projection(t_mlx *mlx);
// MAP_FUNCS_TRANSFORM
void		func_translate_up(t_map *node_addr, t_mlx *mlx);
void		func_translate_down(t_map *node_addr, t_mlx *mlx);
void		func_translate_right(t_map *node_addr, t_mlx *mlx);
void		func_translate_left(t_map *node_addr, t_mlx *mlx);
// MAP_FUNCS_ZOOM
void		func_increase_z(t_map *node_addr, t_mlx *mlx);
void		func_decrease_z(t_map *node_addr, t_mlx *mlx);
// MAP_LOAD
void		load_map(char *crude_map, t_mlx *mlx);
// MAP_OPEN
int			get_map(char *path, t_mlx *mlx);
// MAP_TOOLS
int			count_digits_in_line(char *line);
t_map		*get_next_node(t_mlx *mlx);
void		map_node_iterate(void (*f)(t_map *, t_mlx *), t_mlx *mlx);

// EXIT_ROUTINES.C
int			escape(t_mlx *mlx);
void		abort_load(char *file_contents, char **split, t_mlx *mlx);

#endif