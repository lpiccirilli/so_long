/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:24:03 by lpicciri          #+#    #+#             */
/*   Updated: 2023/09/21 23:15:20 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_map *map)
{
	int	i;
	int	row;

	row = ft_strlen(map->matrix[0]);
	i = 1;
	while(i < map->y_size)
	{
		if (ft_strlen(map->matrix[i]) != row)
		{
			printf("Error the map should be rectangular\n");
			return (-1);
		}
		i++;
	}
	return(0);
}

int	check_top_and_down(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->x_size)
	{
		if(map->matrix[0][i] != '1')
		{
			printf("Error, walls not placed correctly\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while(i < map->x_size)
	{
		if(map->matrix[map->y_size - 1][i] != '1')
		{
			printf("Error, walls not placed correctly\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_left_and_right(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->y_size)
	{
		if(map->matrix[i][0] != '1')
		{
			printf("Error, walls not placed correctly\n");
			return (-1);
		}
		i++;
	}
	return(0);
}

int	check_letters(t_map *map)
{
	if (check_rectangle(map) == -1)
		return (-1);
	if (check_top_and_down(map) == -1)
		return (-1);
	if (check_left_and_right(map) == -1)
		return (-1);
	return (0);
}

