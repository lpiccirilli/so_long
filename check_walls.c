/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:24:03 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/13 15:05:46 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_map *map)
{
	int	i;
	int	row;

	row = ft_strlen(map->matrix[0]);
	i = 1;
	while (i < map->y_size)
	{
		if (ft_strlen(map->matrix[i]) != row)
		{
			ft_printf("Error\n the map should be rectangular\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_top_and_down(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->x_size)
	{
		if (map->matrix[0][i] != '1')
		{
			ft_printf ("Error\n walls not placed correctly\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < map->x_size)
	{
		if (map->matrix[map->y_size - 1][i] != '1')
		{
			ft_printf ("Error\nwalls not placed correctly\n");
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
	while (i < map->y_size)
	{
		if (map->matrix[i][0] != '1')
		{
			ft_printf("Error\nwalls not placed correctly\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_inside(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->y_size - 1)
	{
		j = 1;
		while (j < map->x_size - 1)
		{
			if (map->matrix[i][j] != '0' && map->matrix[i][j] != '1'
				&& map->matrix[i][j] != 'C' && map->matrix[i][j] != 'E'
				&& map->matrix[i][j] != 'P')
			{
				ft_printf("Error\ninvalid character\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_letters(t_map *map)
{
	if (check_rectangle(map) == -1)
		return (-1);
	if (check_top_and_down(map) == -1)
		return (-1);
	if (check_left_and_right(map) == -1)
		return (-1);
	if (check_inside(map) == -1)
		return (-1);
	if (check_p(map) == -1 || check_c(map) == -1 || check_e(map) == -1)
		return (-1);
	return (0);
}
