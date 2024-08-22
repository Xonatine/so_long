/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:52:48 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 11:54:32 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	free_map(t_map *map)
{
	int	j;

	j = 0;
	if (map->land)
	{
		while (map->land[j])
		{
			free (map->land[j]);
			j++;
		}
		free (map->land);
	}
	free (map->player);
	free (map->exit);
	free (map);
}

void	free_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->pl_dw);
	mlx_delete_image(game->mlx, game->pl_up);
	mlx_delete_image(game->mlx, game->pl_lf);
	mlx_delete_image(game->mlx, game->pl_rg);
	mlx_delete_image(game->mlx, game->trinket);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->floor);
	free (game);
}
