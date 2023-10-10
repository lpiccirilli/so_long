/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:20:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/09 16:35:27 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char**av)
{
	t_map	map;
	t_mlx	mlx_data;

	if (ac != 2)
		return (-1);
	if (check(av[1], &map, &mlx_data) == -1)
		return (-1);
	init_mlx(&mlx_data, &map);
	return (0);
}
