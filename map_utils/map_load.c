/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:14:54 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/28 12:44:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	fill_node(t_map *formatted_map, char *split_map, int xi, int y)
{
	if (ft_isdigit(*split_map) || *split_map == '-')
	{
		formatted_map[xi].x = xi;
		formatted_map[xi].y = y;
		formatted_map[xi].z = ft_atoi(split_map);
		return (1);
	}
	return (0);
}

static void	fill_line(t_map *formatted_map, char *split_map, int x, int y)
{
	int		xi;
	int		i;

	xi = 0;
	i = 0;
	while (xi < x)
	{
		if (ft_isdigit(*split_map))
		{
			xi += fill_node(formatted_map, split_map + i, xi, y);
			while (*split_map && *split_map != '\n' && *split_map != ' ')
				split_map++;
		}
		else
			split_map++;
	}
}

static void	fill_matrix(char **file_content_split, t_map **map, int x, int y)
{
	while (y--)
	{
		map[y] = (t_map *)calloc((x + 1), sizeof(t_map));
		fill_line(map[y], file_content_split[y], x, y);
		free(file_content_split[y]);
	}
}

static void	map_information(char *file_contents, char **split_map, t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->map_size_x = count_digits_in_line(*split_map);
	mlx->map_size_y = 0;
	while (split_map[i])
	{
		if (mlx->map_size_x != count_digits_in_line(split_map[i]))
			abort_load(file_contents, split_map, mlx);
		mlx->map_size_y++;
		i++;
	}
}

void	load_map(char *file_contents, t_mlx *mlx)
{
	char	**file_content_split;

	file_content_split = ft_split(file_contents, '\n');
	map_information(file_contents, file_content_split, mlx);
	mlx->map = (t_map **)calloc((mlx->map_size_y + 1), sizeof(t_map *));
	fill_matrix(file_content_split, mlx->map, mlx->map_size_x, mlx->map_size_y);
	free(file_content_split);
}
