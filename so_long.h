/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:34:47 by lpicciri          #+#    #+#             */
/*   Updated: 2023/11/13 14:54:04 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define BUFFER 1000000
# define KEY_ESC 53
# define KEY_Q 12

typedef struct s_map
{
	int		fd;
	char	*temp;
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
	int		x_player;
	int		y_player;
	int		collectable;
	int		moves;
	t_map	*map_data;
}			t_mlx;

int		check_map(t_map *map);
int		check_file(char *file);
int		check(char *path, t_map *map, t_mlx *mlx_data);
int		check_letters(t_map *map);
int		check_top_and_down(t_map *map);
int		check_left_and_right(t_map *map);
int		check_rectangle(t_map *map);
int		check_inside(t_map *map);
int		check_e(t_map *map);
int		check_p(t_map *map);
int		check_c(t_map *map);
void	init_mlx(t_mlx *mlx_data, t_map *map);
int		load_images(t_mlx *mlx);
int		init_map(t_mlx *mlx, t_map *map);
int		move_w(t_mlx *mlx);
int		move_s(t_mlx *mlx);
int		move_a(t_mlx *mlx);
int		move_d(t_mlx *mlx);
int		search_player_x(t_mlx *mlx);
int		search_player_y(t_mlx *mlx);
void	my_exit(t_mlx *mlx);

#endif
