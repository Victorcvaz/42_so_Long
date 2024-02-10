/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:20:24 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/08 17:56:18 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_def **def, char *buff)
{
	(*def)->map = ft_calloc(1, sizeof(t_map));
	if ((*def)->map)
	{
		(*def)->map->buffer = ft_split(buff, '\n');
		if (!(*def)->map->buffer)
		{
			free((*def)->map);
			free((*def)->sprites);
			free(*def);
			return (0);
		}
	}
	else
	{
		free((*def)->sprites);
		free(*def);
	}
	player_init_position(def);
	return (1);
}

void	init_def(t_def **def, char *buffer)
{
	*def = ft_calloc(1, sizeof(t_def));
	if (*def)
	{
		(*def)->sprites = ft_calloc(1, sizeof(t_sprite));
		if (!(*def)->sprites)
		{
			free(*def);
			ft_error(404);
		}
	}
	else
		ft_error(404);
	if (init_map(def, buffer) == 0)
		ft_error(404);
	return ;
}

void	player_init_position(t_def **def)
{
	int	i;
	int	j;

	i = 0;
	while ((*def)->map->buffer[i])
	{
		j = 0;
		while ((*def)->map->buffer[i][j] != '\0')
		{
			if ((*def)->map->buffer[i][j] == 'P')
			{
				(*def)->map->x_init = i;
				(*def)->map->y_init = j;
			}
			j++;
		}
		i++;
	}
}
