/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:14:54 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:28:45 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "map_utils.h"
#include "../fdf.h"
#include <fcntl.h>

static t_map	**load_map(char *crude_map, int x, int y)
{
	t_map	**formatted_map;
	char	**split_map;
	int		xi;
	int		i;

	split_map = ft_split(crude_map, '\n');
	formatted_map = (t_map **)calloc((y + 1), sizeof(t_map *));
	while (y--)
	{
		xi = 0;
		i = 0;
		formatted_map[y] = (t_map *)calloc((x + 1), sizeof(t_map));
		while (xi < x)
		{
			if (ft_isdigit(split_map[y][i]) || split_map[y][i] == '-')
			{
				formatted_map[y][xi].x = xi;
				formatted_map[y][xi].y = y;
				formatted_map[y][xi].z = ft_atoi(split_map[y] + (i));
				xi++;
			}
			if (split_map[y][i] == '-')
				i++;
			i++;
		}
		free(split_map[y]);
	}
	return (formatted_map);
}

static int	count_digits_in_line(char *line)
{
	int	x;

	x = 0;
	while (*line && *line != '\n')
		if (ft_isdigit(*line++))
			x++;
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

int	get_map(char *path, t_mlx *window)
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
	window->map_size_x = x;
	window->map_size_y = y;
	window->map = load_map(file_contents, x, y);
	free(file_contents);
	if (!window->map)
		return (3);
	return (0);
}
