/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:43:09 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 11:57:29 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	controls_game(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_rigth(game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc == 2)
	{
		map = construct_map(argv[argc - 1]);
		if (map->error != false)
		{
			game = malloc(sizeof(t_game));
			init_game(game, map);
			mlx_set_setting(MLX_STRETCH_IMAGE, true);
			print_window(game);
			mlx_key_hook(game->mlx, controls_game, game);
			mlx_loop(game->mlx);
			mlx_terminate(game->mlx);
			free_game (game);
		}
		free_map(map);
	}
	else
		ft_printf("Error\nNº de argumentos incorrecto\n");
	return (0);
}
