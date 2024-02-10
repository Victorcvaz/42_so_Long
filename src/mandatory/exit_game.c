/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:33:01 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/08 09:24:39 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_def **def, int option)
{
	int	i;

	i = 0;
	while ((*def)->map->buffer[i])
	{
		free((*def)->map->buffer[i]);
		i++;
	}
	free((*def)->map->buffer);
	free((*def)->map);
	free((*def)->sprites);
	free(*def);
	ft_error(option);
}

void	clean_images(t_def **def)
{
	mlx_delete_texture((*def)->sprites->background);
	mlx_delete_image((*def)->mlx, (*def)->sprites->bg_tile);
	mlx_delete_texture((*def)->sprites->wall);
	mlx_delete_image((*def)->mlx, (*def)->sprites->wall_img);
	mlx_delete_texture((*def)->sprites->coin);
	mlx_delete_image((*def)->mlx, (*def)->sprites->coin_img);
	mlx_delete_texture((*def)->sprites->player);
	mlx_delete_image((*def)->mlx, (*def)->sprites->player_img);
	mlx_delete_texture((*def)->sprites->exit);
	mlx_delete_image((*def)->mlx, (*def)->sprites->exit_img);
	mlx_delete_texture((*def)->sprites->icon);
}

void	exit_game(t_def **def, int option)
{
	clean_images(def);
	mlx_terminate((*def)->mlx);
	free_game(def, option);
}
