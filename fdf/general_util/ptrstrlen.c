/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrstrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:23:09 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:07:24 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ptrstrlen(t_map	**ptr)
{
	int	i;

	i = 0;
	while (*ptr++)
		i++;
	return (i);
}

int	mapstrlen(t_map	*ptr)
{
	int	i;

	i = 0;
	while (ptr++)
		i++;
	return (i);
}
