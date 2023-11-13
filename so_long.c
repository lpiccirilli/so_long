/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:20:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/11 17:37:42 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char**av)
{
	t_map	map;
	t_mlx	mlx_data;

	if (ac != 2 || check(av[1], &map, &mlx_data) == -1)
	{
		ft_printf("Error\nInvalid map\n");
		exit(0);
	}
	init_mlx(&mlx_data, &map);
	return (0);
}
