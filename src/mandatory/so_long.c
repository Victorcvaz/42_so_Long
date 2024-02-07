/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:28:42 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/07 02:00:52 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_def	*def;

	input_check(&def, argv[1], argc);
	init_game(&def);
	var_init(&def);
	// mlx_hook(def.mlx->window, 2, 1L << 0, key_press, &def);
	mlx_loop(def->mlx);
	free_game(&def, 0);
	return (EXIT_SUCCESS);
}

void	ft_error(int msg_nbr)
{
	if (msg_nbr == 1)
		ft_putstr_fd("Error\nInvalid args\n", 2);
	else if (msg_nbr == 2)
		ft_putstr_fd("Error\nInvalid file\n", 2);
	else if (msg_nbr == 3)
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
	else if (msg_nbr == 4)
		ft_putstr_fd("Error\nAt reading the file\n", 2);
	else if (msg_nbr == 5)
		ft_putstr_fd("Error\nInvalid map content\n", 2);
	else
		ft_putstr_fd("Memory Error\n", 2);
	exit(EXIT_FAILURE);
}

void	var_init(t_def **def)
{
	int	i;
	int	j;

	i = 0;
	(*def)->map->player = 0;
	(*def)->map->start = 0;
	(*def)->map->exit = 0;
	(*def)->map->collectibles = 0;
	(*def)->map->x_init = 0;
	(*def)->map->y_init = 0;
	(*def)->moves = 0;
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
