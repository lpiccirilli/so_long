/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:22:28 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/31 16:01:58 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_player_x(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map_data->matrix[y] != NULL)
	{
		x = 0;
		while (mlx->map_data->matrix[y][x] != '\0')
		{
			if (mlx->map_data->matrix[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	search_player_y(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map_data->matrix[y] != NULL)
	{
		x = 0;
		while (mlx->map_data->matrix[y][x] != '\0')
		{
			if (mlx->map_data->matrix[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

void	my_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->images[0]);
	mlx_destroy_image(mlx->mlx, mlx->images[1]);
	mlx_destroy_image(mlx->mlx, mlx->images[2]);
	mlx_destroy_image(mlx->mlx, mlx->images[3]);
	mlx_destroy_image(mlx->mlx, mlx->images[4]);
	free(mlx->mlx);
	free(mlx->map_data->temp);
	exit(0);
}
