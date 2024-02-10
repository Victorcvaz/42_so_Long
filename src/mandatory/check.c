/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:24 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/08 17:44:28 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_check(t_def **def, char *argv, int argc)
{
	int		fd;
	int		index;
	char	buffer[BUFFER_SIZE];

	index = 0;
	fd = 0;
	buffer[0] = '\0';
	if (argc != 2)
		ft_error(1);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
		ft_error(3);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	index = read(fd, buffer, BUFFER_SIZE);
	if (index == -1)
		ft_error(4);
	buffer[index] = '\0';
	close(fd);
	init_def(def, buffer);
	fill_map_check(def);
}

void	fill_map_check(t_def **def)
{
	int		index;

	(*def)->map->w = ft_strlen((*def)->map->buffer[0]);
	while ((*def)->map->buffer[(*def)->map->h])
		(*def)->map->h++;
	index = 0;
	while (index < (*def)->map->h)
	{
		if (ft_strlen((*def)->map->buffer[index]) != (size_t)(*def)->map->w)
			free_game(def, 5);
		index++;
	}
	check_map(def);
	if ((*def)->map->player != 1
		|| (*def)->map->exit != 1 || (*def)->map->collectibles < 1
		|| (*def)->map->h == (*def)->map->w)
		free_game(def, 5);
}

void	check_map(t_def **def)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < (*def)->map->h)
	{
		j = 0;
		while (j < (*def)->map->w)
		{
			c = (*def)->map->buffer[i][j];
			if (c == 'P')
				(*def)->map->player++;
			if (c == 'C')
				(*def)->map->collectibles++;
			if (c == 'E')
				(*def)->map->exit++;
			if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
				free_game(def, 5);
			j++;
		}
		i++;
	}
	check_map_extend(def);
}

void	check_map_extend(t_def **def)
{
	int		i;

	i = 0;
	while (i < (*def)->map->w)
	{
		if ((*def)->map->buffer[0][i] != '1')
			free_game(def, 5);
		if ((*def)->map->buffer[(*def)->map->h - 1][i] != '1')
			free_game(def, 5);
		i++;
	}
	i = 0;
	while (i < (*def)->map->h)
	{
		if ((*def)->map->buffer[i][0] != '1')
			free_game(def, 5);
		if ((*def)->map->buffer[i][(*def)->map->w - 1] != '1')
			free_game(def, 5);
		i++;
	}
}
