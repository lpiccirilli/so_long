/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:19:44 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/13 15:13:51 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p(t_map *map)
{
	int	x;
	int	y;
	int	cont;

	x = 0;
	cont = 0;
	while(map->matrix[x] != NULL)
	{
		y = 0;
		while(map->matrix[x][y] != '\0')
		{
			if (map->matrix[x][y] == 'P')
				cont++;
			y++;
		}
		x++;
	}
	if (cont != 1)
		return (-1);
	return(0);
}

int	check_c(t_map *map)
{
	int	x;
	int	y;
	int	cont;

	x = 0;
	cont = 0;
	while(map->matrix[x] != NULL)
	{
		y = 0;
		while(map->matrix[x][y] != '\0')
		{
			if (map->matrix[x][y] == 'C')
				cont++;
			y++;
		}
		x++;
	}
	if (cont < 1)
		return (-1);
	return(0);
}
int	check_e(t_map *map)
{
	int	x;
	int	y;
	int	cont;

	x = 0;
	cont = 0;
	while(map->matrix[x] != NULL)
	{
		y = 0;
		while(map->matrix[x][y] != '\0')
		{
			if (map->matrix[x][y] == 'E')
				cont++;
			y++;
		}
		x++;
	}
	if (cont != 1)
		return (-1);
	return(0);
}

