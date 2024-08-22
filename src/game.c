/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:51:33 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/20 20:24:19 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	mlx_image_t	*load_img(t_game *game, char *path);

void	init_game(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = WIDTH * (map->columns + 1);
	y = HEIGHT * (map->rows + 1);
	game->mlx = mlx_init(x, y, "so_long", true);
	game->movements = 0;
	game->map = map;
	game->pl_dw = load_img(game, PJ_DOWN);
	game->pl_up = load_img(game, PJ_UP);
	game->pl_lf = load_img(game, PJ_LEFT);
	game->pl_rg = load_img(game, PJ_RIGHT);
	game->exit = load_img(game, EXIT);
	game->wall = load_img(game, BOX);
	game->floor = load_img(game, FLOOR);
	game->trinket = load_img(game, TRINKET);
}

static	mlx_image_t	*load_img(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (img);
}

void	collect_trinkets(t_map *map, mlx_image_t *img, mlx_image_t *img_p)
{
	int	x;
	int	y;
	int	i;

	x = img_p->instances->x / 128;
	y = img_p->instances->y / 128;
	i = 0;
	if (map->land[y][x] == 'C' && map->n_trinkets > 0)
	{
		while (i >= 0)
		{
			if (img->instances[i].x / 128 == x
				&& img->instances[i].y / 128 == y)
			{
				if (img->instances[i].enabled == true)
				{
					img->instances[i].enabled = false;
					map->n_trinkets--;
				}
				break ;
			}
			i++;
		}
	}
}

void	open_exit(t_map *map, mlx_image_t *img_p, mlx_t *mlx)
{
	int	x;
	int	y;

	x = img_p->instances->x / 128;
	y = img_p->instances->y / 128;
	if (map->land[y][x] == 'E' && map->n_trinkets == 0)
	{
		mlx_close_window(mlx);
		ft_printf("Ganaste\n");
	}
}
