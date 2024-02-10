/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:46 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/09 02:26:05 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_def **def)
{
	int	height;
	int	width;

	width = (*def)->map->w * WALL_SIZE;
	height = (*def)->map->h * WALL_SIZE;
	(*def)->map->item_count = (*def)->map->collectibles;
	if (width > 1700)
		width = 1700;
	if (height > 900)
		height = 900;
	(*def)->mlx = mlx_init(width, height, "So_long", false);
	if (!(*def)->mlx)
	{
		mlx_close_window((*def)->mlx);
		free_game(def, 404);
	}
	(*def)->sprites = ft_calloc(1, sizeof(t_sprite));
	if (!(*def)->sprites)
	{
		mlx_close_window((*def)->mlx);
		free_game(def, 404);
	}
	load_images(def);
	position_to_draw(def, width, height);
}

void	load_images(t_def **def)
{
	(*def)->sprites->background = mlx_load_png("sprites/bg/bg.png");
	(*def)->sprites->bg_tile = mlx_texture_to_image((*def)->mlx, 
			(*def)->sprites->background);
	(*def)->sprites->wall = mlx_load_png("sprites/wall/wall.png");
	(*def)->sprites->wall_img = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->wall);
	(*def)->sprites->coin = mlx_load_png("sprites/item/item.png");
	(*def)->sprites->coin_img = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->coin);
	(*def)->sprites->player = mlx_load_png("sprites/player/porco_aranha1.png");
	(*def)->sprites->player_img = mlx_texture_to_image((*def)->mlx, 
			(*def)->sprites->player);
	(*def)->sprites->exit = mlx_load_png("sprites/exit/exit.png");
	(*def)->sprites->exit_img = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->exit);
	(*def)->sprites->icon = mlx_load_png("sprites/player/porco_aranha1.png");
	mlx_set_icon((*def)->mlx, (*def)->sprites->icon);
}

void	position_to_draw(t_def **def, int w, int h)
{
	int	x;
	int	y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			mlx_image_to_window((*def)->mlx, (*def)->sprites->bg_tile, x, y);
			x += 64;
		}
		y += 64;
	}
	y = 0;
	while ((*def)->map->buffer[y])
	{
		x = 0;
		while ((*def)->map->buffer[y][x])
		{
			draw_map(def, y, x);
			x++;
		}
		y++;
	}
}

void	draw_map(t_def **def, int i, int j)
{
	if ((*def)->map->buffer[i][j] == '1')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->wall_img,
			j * WALL_SIZE, i * WALL_SIZE);
	else if ((*def)->map->buffer[i][j] == 'C')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->coin_img,
			j * WALL_SIZE, i * WALL_SIZE);
	else if ((*def)->map->buffer[i][j] == 'P')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->player_img,
			j * WALL_SIZE, i * WALL_SIZE);
	else if ((*def)->map->buffer[i][j] == 'E')
	{
		mlx_image_to_window((*def)->mlx, (*def)->sprites->exit_img,
			j * WALL_SIZE, i * WALL_SIZE);
		(*def)->sprites->exit_img->enabled = false;
	}
}
