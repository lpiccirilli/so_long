/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:20:12 by lpicciri          #+#    #+#             */
/*   Updated: 2023/09/20 16:11:35 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void* win;
}				t_data;


int main()
{
	void* mlx;
	char *image = "sprites/wooden.xpm";
	int		img_width = 64;
	int		img_height = 64;
	t_data data;

	mlx = mlx_init();
	data.win = mlx_new_window(mlx, 500, 500, "so_long");
	mlx_xpm_file_to_image(mlx, image, &img_width, &img_height);
	mlx_loop(mlx);
	return (0);
}
