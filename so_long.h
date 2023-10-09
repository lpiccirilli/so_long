/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:34:47 by lpicciri          #+#    #+#             */
/*   Updated: 2023/10/09 16:18:39 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define BUFFER 1000000

//keys

# define KEY_ESC 53
# define KEY_Q 12

typedef struct s_map
{
	int		fd;
	char	**map;
	char	**matrix;
	int		x_size;
	int		y_size;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*images[6];
	int		width;
	int		height;
	int		map_width;
	int		map_height;
}			t_mlx;

int		check_map(t_map *map);
int		check_file(char *file);
int		check(char *path, t_map *map, t_mlx *mlx_data);
int		check_letters(t_map *map);
int		check_top_and_down(t_map *map);
int		check_left_and_right(t_map *map);
void	init_mlx(t_mlx *mlx_data, t_map *map);
int		load_images(t_mlx* mlx);

# endif
