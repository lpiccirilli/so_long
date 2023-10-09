/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:15:32 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/09 16:17:22 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_mlx* mlx)
{
	mlx->images[0] = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall.xpm", &mlx->height, &mlx->width);
	mlx->images[1] = mlx_xpm_file_to_image(mlx->mlx, "./sprites/collect.xpm", &mlx->height, &mlx->width);
	mlx->images[2] = mlx_xpm_file_to_image(mlx->mlx, "./sprites/player.xpm", &mlx->height, &mlx->width);
	mlx->images[3] = mlx_xpm_file_to_image(mlx->mlx, "./sprites/exit.xpm", &mlx->height, &mlx->width);
	mlx->images[4] = mlx_xpm_file_to_image(mlx->mlx, "./sprites/floor.xpm", &mlx->height, &mlx->width);
}

int	init_map(t_mlx *mlx,t_map *map)
{

}
