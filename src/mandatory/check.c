/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:24 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/01/26 00:05:16 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_check(t_def *def, char *argv, int argc)
{
	int		fd;
	int		index;
	char	buff[BUFFER_SIZE];

	if (argc != 2)
		ft_error(1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
		ft_error(3);
	index = read(fd, buff, BUFFER_SIZE);
	if (index == -1)
		ft_error(4);
	buff[index] = '\0';
	def = ft_calloc(1, sizeof(t_def));
	if (def == NULL)
		ft_error(404);
	(def)->map = ft_calloc(1, sizeof(t_map));
	if ((def)->map == NULL)
	{
		free(def);
		ft_error(404);
	}
	fill_map_check(def, fd, buff);
}

void	fill_map_check(t_def *def, int fd, char *buff)
{
	int		index;

	def->map->buffer = ft_split(buff, '\n');
	if (def->map->buffer == NULL)
		ft_error(404);
	def->map->h = 0;
	def->map->w = ft_strlen(def->map->buffer[0]);
	while (def->map->buffer[def->map->h])
		def->map->h++;
	index = 0;
	while (index < def->map->h)
	{
		if (ft_strlen(def->map->buffer[index]) != (size_t)def->map->w)
			free_game(def, 5);
		index++;
	}
	check_map(def);
	if (def->map->player != 1
		|| def->map->exit != 1 || def->map->collectibles < 1
		|| def->map->h == def->map->w)
		free_game(def, 5);
	close(fd);
}

void	check_map(t_def *def)
{
	int		i;
	int		j;

	i = 0;
	while (i < def->map->h)
	{
		j = 0;
		while (j < def->map->w)
		{
			if (def->map->buffer[i][j] == 'P')
				def->map->player++;
			if (def->map->buffer[i][j] == 'C')
				def->map->collectibles++;
			if (def->map->buffer[i][j] == 'E')
				def->map->exit++;
			if (def->map->buffer[i][j] != '1' && def->map->buffer[i][j] != '0'
				&& def->map->buffer[i][j] != 'P' 
					&& def->map->buffer[i][j] != 'C'
						&& def->map->buffer[i][j] != 'E')
				free_game(def, 5);
			j++;
		}
		i++;
	}
	check_map_extend(def);
}

void	check_map_extend(t_def *def)
{
	int		i;

	i = 0;
	while (i < def->map->w)
	{
		if (def->map->buffer[0][i] != '1')
			free_game(def, 5);
		if (def->map->buffer[def->map->h - 1][i] != '1')
			free_game(def, 5);
		i++;
	}
	i = 0;
	while (i < def->map->h)
	{
		if (def->map->buffer[i][0] != '1')
			free_game(def, 5);
		if (def->map->buffer[i][def->map->w - 1] != '1')
			free_game(def, 5);
		i++;
	}
}
