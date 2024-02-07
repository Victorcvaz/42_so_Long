/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorcvaz <victorcvaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:37 by victorcvaz        #+#    #+#             */
/*   Updated: 2024/02/07 01:41:39 by victorcvaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	only_escape(mlx_key_data_t key, t_def **def)
{
	if (key.key == MLX_KEY_ESCAPE)
		exit_game(def);
}
