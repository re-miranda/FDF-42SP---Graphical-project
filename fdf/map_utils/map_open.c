/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:14:54 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 02:54:43 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

static int	count_digits_in_line(char *line)
{
	int	x;

	x = 0;
	while (*line && *line != '\n')
	{
		if (ft_isdigit(*line++))
		{
			x++;
			while (ft_isdigit(*line))
				line++;
		}
	}
	return (x);
}

static int	map_validation(char	*map, int *x, int *y)
{
	*x = count_digits_in_line(map);
	*y = 0;
	if (!*x)
		return (1);
	while (*map && *map != '\n')
	{
		if (count_digits_in_line(map) != *x)
			return (2);
		y[0]++;
		map = ft_strchr(map, '\n') + 1;
	}
	return (0);
}

static char	*open_map(char *path)
{
	int		fd;
	char	*map;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (NULL);
	map = get_whole_file(fd);
	close(fd);
	return (map);
}

int	get_map(char *path, t_mlx *mlx)
{
	char	*file_contents;
	int		x;
	int		y;

	file_contents = open_map(path);
	if (!file_contents)
		return (1);
	if (map_validation(file_contents, &x, &y))
	{
		free(file_contents);
		return (2);
	}
	mlx->map_size_x = x;
	mlx->map_size_y = y;
	mlx->map = load_map(file_contents, x, y);
	free(file_contents);
	if (!mlx->map)
		return (3);
	isometric_projection(mlx);
	return (0);
}
