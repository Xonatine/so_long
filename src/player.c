/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:29:41 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/12 16:18:53 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

bool	its_wall(t_map *map, mlx_image_t *img, char key);

void	move_down(t_game *game)
{
	if (game->pl_dw->instances->enabled == false)
		game->pl_dw->instances->enabled = true;
	if (game->pl_up->instances->enabled == true)
		game->pl_up->instances->enabled = false;
	if (game->pl_lf->instances->enabled == true)
		game->pl_lf->instances->enabled = false;
	if (game->pl_rg->instances->enabled == true)
		game->pl_rg->instances->enabled = false;
	if (its_wall(game->map, game->pl_dw, 'D') == true)
	{
		game->pl_dw->instances->y += 128;
		game->pl_up->instances->y += 128;
		game->pl_lf->instances->y += 128;
		game->pl_rg->instances->y += 128;
		game->movements++;
		ft_printf("Number of movements: %i\n", game->movements);
	}
	collect_trinkets(game->map, game->trinket, game->pl_dw);
	open_exit(game->map, game->pl_dw, game->mlx);
}

void	move_up(t_game *game)
{
	if (game->pl_dw->instances->enabled == true)
		game->pl_dw->instances->enabled = false;
	if (game->pl_up->instances->enabled == false)
		game->pl_up->instances->enabled = true;
	if (game->pl_lf->instances->enabled == true)
		game->pl_lf->instances->enabled = false;
	if (game->pl_rg->instances->enabled == true)
		game->pl_rg->instances->enabled = false;
	if (its_wall(game->map, game->pl_up, 'U') == true)
	{
		game->pl_dw->instances->y -= 128;
		game->pl_up->instances->y -= 128;
		game->pl_lf->instances->y -= 128;
		game->pl_rg->instances->y -= 128;
		game->movements++;
		ft_printf("Number of movements: %i\n", game->movements);
	}
	collect_trinkets(game->map, game->trinket, game->pl_up);
	open_exit(game->map, game->pl_up, game->mlx);
}

void	move_left(t_game *game)
{
	if (game->pl_dw->instances->enabled == true)
		game->pl_dw->instances->enabled = false;
	if (game->pl_up->instances->enabled == true)
		game->pl_up->instances->enabled = false;
	if (game->pl_lf->instances->enabled == false)
		game->pl_lf->instances->enabled = true;
	if (game->pl_rg->instances->enabled == true)
		game->pl_rg->instances->enabled = false;
	if (its_wall(game->map, game->pl_lf, 'L') == true)
	{
		game->pl_dw->instances->x -= 128;
		game->pl_up->instances->x -= 128;
		game->pl_lf->instances->x -= 128;
		game->pl_rg->instances->x -= 128;
		game->movements++;
		ft_printf("Number of movements: %i\n", game->movements);
	}
	collect_trinkets(game->map, game->trinket, game->pl_lf);
	open_exit(game->map, game->pl_lf, game->mlx);
}

void	move_rigth(t_game *game)
{
	if (game->pl_dw->instances->enabled == true)
		game->pl_dw->instances->enabled = false;
	if (game->pl_up->instances->enabled == true)
		game->pl_up->instances->enabled = false;
	if (game->pl_lf->instances->enabled == true)
		game->pl_lf->instances->enabled = false;
	if (game->pl_rg->instances->enabled == false)
		game->pl_rg->instances->enabled = true;
	if (its_wall(game->map, game->pl_rg, 'R') == true)
	{
		game->pl_dw->instances->x += 128;
		game->pl_up->instances->x += 128;
		game->pl_lf->instances->x += 128;
		game->pl_rg->instances->x += 128;
		game->movements++;
		ft_printf("Number of movements: %i\n", game->movements);
	}
	collect_trinkets(game->map, game->trinket, game->pl_rg);
	open_exit(game->map, game->pl_rg, game->mlx);
}

bool	its_wall(t_map *map, mlx_image_t *img, char key)
{
	int	x;
	int	y;

	x = img->instances->x / 128;
	y = img->instances->y / 128;
	if (key == 'R')
		if (map->land[y][x + 1] == '1')
			return (false);
	if (key == 'L')
		if (map->land[y][x - 1] == '1')
			return (false);
	if (key == 'U')
		if (map->land[y - 1][x] == '1')
			return (false);
	if (key == 'D')
		if (map->land[y + 1][x] == '1')
			return (false);
	return (true);
}
