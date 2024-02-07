/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:25:11 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/07 10:34:53 by victorcvaz       ###   ########.fr       */
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

# define WALL_SIZE 32

typedef struct s_map	t_map;
struct					s_map
{
	char	**buffer;
	int		player;
	int		start;
	int		collectibles;
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
	t_sprite	*sprite;
	int			moves;
};

void	ft_error(int msg_nbr);
void	var_init(t_def **def);
void	input_check(t_def **def, char *argv, int argc);
void	fill_map_check(t_def **def, int fd, char *buff);
void	check_map(t_def **def);
void	check_map_extend(t_def **def);
void	free_game(t_def **def, int option);
void	clean_images(t_def **def);
void	exit_game(t_def **def);
void	init_game(t_def **def);
void	load_images(t_def **def);
void	position_to_draw(t_def **def, int w, int h);
void	draw_map(t_def **def, int i, int j);
void	only_escape(mlx_key_data_t key, t_def **def);

#endif
