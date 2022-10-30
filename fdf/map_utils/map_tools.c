/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:19:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/28 11:33:51 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_digits_in_line(char *line)
{
	int	x;

	x = 0;
	while (*line && *line != '\n')
	{
		if (ft_isdigit(*line++))
		{
			x++;
			while (*line && *line != '\n' && *line != ' ')
				line++;
		}
	}
	return (x);
}

t_map	*get_next_node(t_mlx *mlx)
{
	static int	i;
	static int	j;

	if (i >= mlx->map_size_x)
	{
		i = 0;
		j++;
	}
	if (j >= mlx->map_size_y)
	{
		j = 0;
		return (NULL);
	}
	return (&mlx->map[j][i++]);
}

void	map_node_iterate(void (*f)(t_map *, t_mlx *), t_mlx *mlx)
{
	t_map	*node_addr;

	node_addr = get_next_node(mlx);
	while (node_addr)
	{
		f(node_addr, mlx);
		node_addr = get_next_node(mlx);
	}
	put_map(mlx);
}
