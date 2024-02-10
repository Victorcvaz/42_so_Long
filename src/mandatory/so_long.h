/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:25:11 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/09 23:32:11 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WALL_SIZE 64

typedef struct s_map	t_map;
struct					s_map
{
	char	**buffer;
	int		player;
	int		start;
	int		collectibles;
	int		item_count;
	int		exit;
	int		x_init;
	int		y_init;
	int		h;
	int		w;
};

typedef struct s_sprite	t_sprite;
struct					s_sprite
{
	mlx_texture_t	*background;
	mlx_image_t		*bg_tile;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_img;
	mlx_texture_t	*coin;
	mlx_image_t		*coin_img;
	mlx_texture_t	*player;
	mlx_image_t		*player_img;
	mlx_texture_t	*exit;
	mlx_image_t		*exit_img;
	mlx_texture_t	*icon;
};

typedef struct s_def	t_def;
struct					s_def
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprite	*sprites;
	int			moves;
};

void	ft_error(int msg_nbr);
void	init_def(t_def **def, char *buffer);
int		init_map(t_def **def, char *buff);
void	player_init_position(t_def **def);
void	input_check(t_def **def, char *argv, int argc);
void	fill_map_check(t_def **def);
void	check_map(t_def **def);
void	check_map_extend(t_def **def);
void	free_game(t_def **def, int option);
void	clean_images(t_def **def);
void	exit_game(t_def **def, int option);
void	init_game(t_def **def);
void	load_images(t_def **def);
void	position_to_draw(t_def **def, int w, int h);
void	draw_map(t_def **def, int i, int j);
void	ft_hook(mlx_key_data_t keydata, t_def **def);
int		move_y(t_def **def, int y);
int		move_x(t_def **def, int x);
void	enable_portal(t_def **def);
void	disable_collectible(t_def **def);

#endif
