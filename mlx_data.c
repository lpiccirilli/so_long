/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:50:32 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/11 17:19:43 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectable_count(char **map)
{
	int	x;
	int	y;
	int	cont;

	cont = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				cont++;
			x++;
		}
		y++;
	}
	return (cont);
}

int	key_hook(int keycode, t_mlx *mlx_data)
{
	int	current_move;

	current_move = mlx_data->moves;
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	mlx_data->x_player = search_player_x(mlx_data);
	mlx_data->y_player = search_player_y(mlx_data);
	if (keycode == 13)
		mlx_data->moves += move_w(mlx_data);
	if (keycode == 1)
		mlx_data->moves += move_s(mlx_data);
	if (keycode == 0)
		mlx_data->moves += move_a(mlx_data);
	if (keycode == 2)
		mlx_data->moves += move_d(mlx_data);
	if (mlx_data->moves != current_move)
		ft_printf("Moves: %d\n", mlx_data->moves);
	init_map(mlx_data, mlx_data->map_data);
	return (0);
}

void	init_mlx(t_mlx *mlx_data, t_map *map)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->map_width,
			mlx_data->map_height, "so_long");
	mlx_data->map_data = map;
	mlx_data->moves = 0;
	mlx_data->x_player = 0;
	mlx_data->y_player = 0;
	mlx_data->collectable = collectable_count(map->matrix);
	if (load_images(mlx_data) != 0)
		my_exit (mlx_data);
	if (init_map(mlx_data, map) != 0)
		my_exit (mlx_data);
	mlx_key_hook(mlx_data->win, key_hook, mlx_data);
	mlx_loop(mlx_data->mlx);
}
