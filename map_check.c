/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:10:35 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/05 17:52:07 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b' || file[i - 4] != '.')
		return (-1);
	return (0);
}
int	check_map(t_map *map)
{
	char *temp;
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	if (!(temp = malloc(sizeof(char) * BUFFER)))
		return (-1);
	read(map->fd, temp, BUFFER);
	while(temp[i] != '\0')
	{
		if (temp[i] == '\n')
			cont++;
		i++;
	}
	map->matrix = ft_split(temp, '\n');
	map->matrix[cont] = NULL;
	map->x_size = ft_strlen(map->matrix[0]);
	map->y_size = cont;
	if (check_letters(map) == -1)
		return (-1);
	free(temp);
	if (!map->matrix)
		return (-1);
	return (0);
}

int	check(char *path, t_map *map, t_mlx *mlx_data)
{
	if (check_file(path) == -1)
		return (-1);
	map->fd = open(path, O_RDONLY);
	if (check_map(map) == -1)
		return (-1);
	mlx_data->map_height = map->y_size * 64;
	mlx_data->map_width = map->x_size * 64;
	return (0);
}
