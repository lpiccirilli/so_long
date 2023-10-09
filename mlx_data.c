/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:50:32 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/09 16:18:25 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(int keycode, t_mlx *mlx_data)
{
	if (keycode != KEY_ESC && keycode != KEY_Q)
		return (0);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
}

void	init_mlx(t_mlx *mlx_data, t_map *map)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->map_width, mlx_data->map_height, "so_long");
	load_images(mlx_data);
	init_map(mlx_data, map);
	mlx_key_hook(mlx_data->win, exit_hook, mlx_data);
	mlx_loop(mlx_data->mlx);
}
