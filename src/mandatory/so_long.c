/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:28:42 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/11 04:51:43 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_def	*def;

	input_check(&def, argv[1], argc);
	init_game(&def);
	mlx_key_hook(def->mlx, (void *) ft_hook, &def);
	mlx_loop(def->mlx);
	exit_game(&def, 0);
	return (EXIT_SUCCESS);
}

void	ft_error(int msg_nbr)
{
	if (msg_nbr == 0)
		ft_putstr_fd("Closing the game, thanks for playing!\n", 2);
	else if (msg_nbr == 1)
		ft_putstr_fd("Error: [Invalid args]\n", 2);
	else if (msg_nbr == 2)
		ft_putstr_fd("Error: [Invalid file]\n", 2);
	else if (msg_nbr == 3)
		ft_putstr_fd("Error: [Invalid file extension]\n", 2);
	else if (msg_nbr == 4)
		ft_putstr_fd("Error: [At reading the file]\n", 2);
	else if (msg_nbr == 5)
		ft_putstr_fd("Error: [Invalid map content]\n", 2);
	else if (msg_nbr == 6)
		ft_putstr_fd("Good job player one, you finished the game!\n", 2);
	else
		ft_putstr_fd("Memory Error\n", 2);
	exit(EXIT_FAILURE);
}
