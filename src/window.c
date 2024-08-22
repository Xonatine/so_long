/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:56:27 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/20 20:18:50 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	void	print_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y <= game->map->rows)
	{
		x = 0;
		while (x <= game->map->columns)
		{
			mlx_image_to_window(game->mlx, game->floor, (x / 2) * 256, y * 128);
			x++;
		}
		y++;
	}
}

static	void	print_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y <= game->map->rows)
	{
		x = 0;
		while (x <= game->map->columns)
		{
			if (game->map->land[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall, x * 128, y * 128);
			if (game->map->land[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->trinket, x * 128, y * 128);
			if (game->map->land[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit, x * 128, y * 128);
			x++;
		}
		y++;
	}
}

static	void	print_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y <= game->map->rows)
	{
		x = 0;
		while (x <= game->map->columns)
		{
			if (game->map->land[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->pl_dw, x * 128, y * 128);
				mlx_image_to_window(game->mlx, game->pl_up, x * 128, y * 128);
				game->pl_up->instances->enabled = false;
				mlx_image_to_window(game->mlx, game->pl_lf, x * 128, y * 128);
				game->pl_lf->instances->enabled = false;
				mlx_image_to_window(game->mlx, game->pl_rg, x * 128, y * 128);
				game->pl_rg->instances->enabled = false;
			}
			x++;
		}
		y++;
	}
}

void	print_window(t_game *game)
{
	print_background(game);
	print_walls(game);
	print_player(game);
}
