/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:14:54 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 11:06:38 by rmiranda         ###   ########.fr       */
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

static void	fill_array(t_map *formatted_map, char *split_map, int x, int y)
{
	int		xi;
	int		i;

	xi = 0;
	i = 0;
	while (xi < x)
	{
		xi += fill_node(formatted_map, split_map + i, xi, y);
		if (split_map[i] == '-')
			i++;
		while (ft_isdigit(split_map[i]))
			i++;
		if (split_map[i] == ',')
			i += 9;
		i++;
	}
}

t_map	**load_map(char *crude_map, int x, int y)
{
	t_map	**formatted_map;
	char	**split_map;

	split_map = ft_split(crude_map, '\n');
	formatted_map = (t_map **)calloc((y + 1), sizeof(t_map *));
	while (y--)
	{
		formatted_map[y] = (t_map *)calloc((x + 1), sizeof(t_map));
		fill_array(formatted_map[y], split_map[y], x, y);
		free(split_map[y]);
	}
	free(split_map);
	return (formatted_map);
}
