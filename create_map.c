/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:15:32 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/10 18:34:45 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_mlx *mlx)
{
	mlx->images[0] = mlx_xpm_file_to_image (mlx->mlx, "./sprites/wall.xpm",
			&mlx->height, &mlx->width);
	mlx->images[1] = mlx_xpm_file_to_image (mlx->mlx, "./sprites/collect.xpm",
			&mlx->height, &mlx->width);
	mlx->images[2] = mlx_xpm_file_to_image (mlx->mlx, "./sprites/player.xpm",
			&mlx->height, &mlx->width);
	mlx->images[3] = mlx_xpm_file_to_image (mlx->mlx, "./sprites/exit.xpm",
			&mlx->height, &mlx->width);
	mlx->images[4] = mlx_xpm_file_to_image (mlx->mlx, "./sprites/floor.xpm",
			&mlx->height, &mlx->width);
	return (0);
}

int	init_map(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->matrix[y] != NULL)
	{
		while (map->matrix[y][x] != '\0')
		{
			if (map->matrix[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images[0], x * 64, y * 64);
			if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images[4], x * 64, y * 64);
			if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images[1], x * 64, y * 64);
			if (map->matrix[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images[3], x * 64, y * 64);
			if (map->matrix[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images[2], x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
