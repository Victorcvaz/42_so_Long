/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:25:11 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/01/26 12:32:42 by victorcvaz       ###   ########.fr       */
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
	int		exit;
	int		x_init;
	int		y_init;
	int		collectibles;
	int		w;
	int		h;
};

typedef struct s_sprite	t_sprite;
struct					s_sprite
{
	mlx_texture_t	*background;
	mlx_image_t		*background_img;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_img;
	mlx_texture_t	*coin;
	mlx_image_t		*coin_img;
	mlx_texture_t	*player;
	mlx_image_t		*player_img;
	mlx_texture_t	*portal;
	mlx_image_t		*portal_img;
	mlx_texture_t	*exit;
	mlx_image_t		*exit_img;
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
void	var_init(t_def *def);
void	input_check(t_def *def, char *argv, int argc);
void	fill_map_check(t_def *def, int fd, char *buff);
void	check_map(t_def *def);
void	check_map_extend(t_def *def);
void	free_game(t_def *def, int option);
void	clean_images(t_def *def);
void	init_game(t_def *def);

#endif
