/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:37 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/10 11:20:54 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, t_def **def)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window((*def)->mlx);
		exit_game(def, 0);
	}
	else if (((keydata.key == MLX_KEY_UP) || (keydata.key == MLX_KEY_W))
		&& keydata.action == MLX_PRESS && move_y(def, -1))
		(*def)->sprites->player_img->instances->y -= 64;
	else if (((keydata.key == MLX_KEY_DOWN) || (keydata.key == MLX_KEY_S))
		&& keydata.action == MLX_PRESS && move_y(def, 1))
		(*def)->sprites->player_img->instances->y += 64;
	else if (((keydata.key == MLX_KEY_LEFT) || (keydata.key == MLX_KEY_A))
		&& keydata.action == MLX_PRESS && move_x(def, -1))
		(*def)->sprites->player_img->instances->x -= 64;
	else if (((keydata.key == MLX_KEY_RIGHT) || (keydata.key == MLX_KEY_D))
		&& keydata.action == MLX_PRESS && move_x(def, 1))
		(*def)->sprites->player_img->instances->x += 64;
	disable_collectible(def);
	enable_portal(def);
}

int	move_y(t_def **def, int y)
{
	if ((*def)->map->buffer[(*def)->sprites->player_img->instances->y / 64 + y]
		[(*def)->sprites->player_img->instances->x / 64] != '1')
	{
		if ((*def)->map->buffer[(*def)->sprites->player_img->instances->y
				/ 64 + y]
			[(*def)->sprites->player_img->instances->x / 64] == 'E')
		{
			if ((*def)->sprites->exit_img->enabled)
				exit_game(def, 6);
		}
		(*def)->moves++;
		printf("Moves: %d\n", (*def)->moves);
		return (1);
	}
	return (0);
}

int	move_x(t_def **def, int x)
{
	if ((*def)->map->buffer[(*def)->sprites->player_img->instances->y / 64]
		[(*def)->sprites->player_img->instances->x / 64 + x] != '1')
	{
		if ((*def)->map->buffer[(*def)->sprites->player_img->instances->y / 64]
			[(*def)->sprites->player_img->instances->x / 64 + x] == 'E')
		{
			if ((*def)->sprites->exit_img->enabled)
				exit_game(def, 6);
		}
		(*def)->moves++;
		printf("Moves: %d\n", (*def)->moves);
		return (1);
	}
	return (0);
}

void	enable_portal(t_def **def)
{
	if ((*def)->map->item_count == 0)
	{
		(*def)->sprites->exit_img->enabled = true;
	}
}

void	disable_collectible(t_def **def)
{
	int	x_player;
	int	y_player;
	int	x_item;
	int	y_item;
	int	i;

	if ((*def)->map->buffer[(*def)->sprites->player_img->instances->y / 64]
		[(*def)->sprites->player_img->instances->x / 64] == 'C')
	{
		x_player = (*def)->sprites->player_img->instances->x;
		y_player = (*def)->sprites->player_img->instances->y;
		i = -1;
		while (++i < (*def)->map->collectibles)
		{
			x_item = (*def)->sprites->coin_img->instances[i].x;
			y_item = (*def)->sprites->coin_img->instances[i].y;
			if (x_player == x_item && y_player == y_item
				&& (*def)->sprites->coin_img->instances[i].enabled)
			{
				(*def)->sprites->coin_img->instances[i].enabled = false;
				(*def)->map->item_count--;
				return ;
			}
		}
	}
}
