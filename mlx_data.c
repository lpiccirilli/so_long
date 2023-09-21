/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:50:32 by lpicciri          #+#    #+#             */
/*   Updated: 2023/09/22 00:14:36 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(int keycode, t_mlx *mlx_data)
{
	printf("keycode: %d\n", keycode);
	if (keycode != KEY_ESC && keycode != KEY_Q)
		return (0);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
}

void	init_mlx(t_mlx *mlx_data)
{
	void *image;
	int width = 100;
	int height = 100;

	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, 1920, 1080, "so_long");
	image = mlx_xpm_file_to_image(mlx_data->mlx, "./sprites/wooden.xpm", &width, &height);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, image, 0, 0);
	mlx_key_hook(mlx_data->win, exit_hook, mlx_data);
	mlx_loop(mlx_data->mlx);
}
