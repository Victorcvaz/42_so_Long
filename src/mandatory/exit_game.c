/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:33:01 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/01/26 00:04:11 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_def *def, int option)
{
	int	i;

	i = 0;
	while (def->map->buffer[i])
	{
		free(def->map->buffer[i]);
		i++;
	}
	free(def->map->buffer);
	free(def->map);
	free(def);
	ft_error(option);
}

void	clean_images(t_def *def)
{
	mlx_delete_texture(def->sprite->background);
	mlx_delete_image(def->mlx, def->sprite->background_img);
	mlx_delete_texture(def->sprite->wall);
	mlx_delete_image(def->mlx, def->sprite->wall_img);
	mlx_delete_texture(def->sprite->coin);
	mlx_delete_image(def->mlx, def->sprite->coin_img);
	mlx_delete_texture(def->sprite->player);
	mlx_delete_image(def->mlx, def->sprite->player_img);
	mlx_delete_texture(def->sprite->portal);
	mlx_delete_image(def->mlx, def->sprite->portal_img);
	mlx_delete_texture(def->sprite->exit);
	mlx_delete_image(def->mlx, def->sprite->exit_img);
}
