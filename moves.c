/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:41:28 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/11 17:19:48 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_w(t_mlx *mlx)
{
	if (mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] == '1')
		return (0);
	if (mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] == 'E')
	{
		if (mlx->collectable == 0)
		{
			printf("Moves: %d\n", mlx->moves + 1);
			my_exit (mlx);
		}
		else
			return (0);
	}
	if (mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] == '0')
	{
		mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
	}
	if (mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] == 'C')
	{
		mlx->map_data->matrix[mlx->y_player - 1][mlx->x_player] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
		mlx->collectable--;
	}
	return (1);
}

int	move_s(t_mlx *mlx)
{
	if (mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] == '1')
		return (0);
	if (mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] == 'E')
	{
		if (mlx->collectable == 0)
		{
			printf("Moves: %d\n", mlx->moves + 1);
			my_exit (mlx);
		}
		else
			return (0);
	}
	if (mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] == '0')
	{
		mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
	}
	if (mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] == 'C')
	{
		mlx->map_data->matrix[mlx->y_player + 1][mlx->x_player] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
		mlx->collectable--;
	}
	return (1);
}

int	move_a(t_mlx *mlx)
{
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] == '1')
		return (0);
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] == 'E')
	{
		if (mlx->collectable == 0)
		{
			ft_printf("Moves: %d\n", mlx->moves + 1);
			my_exit (mlx);
		}
		else
			return (0);
	}
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] == '0')
	{
		mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
	}
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] == 'C')
	{
		mlx->map_data->matrix[mlx->y_player][mlx->x_player - 1] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
		mlx->collectable--;
	}
	return (1);
}

int	move_d(t_mlx *mlx)
{
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] == '1')
		return (0);
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] == 'E')
	{
		if (mlx->collectable == 0)
		{
			printf("Moves: %d\n", mlx->moves + 1);
			my_exit (mlx);
		}
		else
			return (0);
	}
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] == '0')
	{
		mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
	}
	if (mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] == 'C')
	{
		mlx->map_data->matrix[mlx->y_player][mlx->x_player + 1] = 'P';
		mlx->map_data->matrix[mlx->y_player][mlx->x_player] = '0';
		mlx->collectable--;
	}
	return (1);
}
