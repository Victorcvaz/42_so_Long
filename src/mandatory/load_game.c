/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:46 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/01/26 00:52:17 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_def *def)
{
	int	height;
	int	width;

	width = def->map->w * WALL_SIZE;
	height = def->map->h * WALL_SIZE;
	if (width > 1600)
		width = 1600;
	if (height > 900)
		height = 900;
	def->mlx = mlx_init(width, height, "So_long", false);
	if (!def->mlx)
	{
		mlx_close_window(def->mlx);
		free_game(def, 404);
	}
}
