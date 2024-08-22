/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:15 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 12:08:23 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	void	rows_columns(t_map *map, char *path)
{
	int	i;
	int	j;

	map->error = true;
	map->land = read_map(path);
	if (!map->land || map->land == NULL)
	{
		ft_printf("Error\nMapa no encontrado\n");
		map->error = false;
	}
	i = 0;
	j = 0;
	if (map->land != NULL)
	{
		while (map->land[i])
			i++;
		while (map->land[0][j] == '1')
			j++;
	}
	map->rows = i - 1;
	if (j != 0)
		map->columns = j - 1;
	else
		map->columns = j;
}

static	void	count_trinkets(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->land[i])
	{
		j = 0;
		while (map->land[i][j])
		{
			if (map->land[i][j] == 'P')
			{
				map->n_players++;
				map->x = j;
				map->y = i;
			}
			if (map->land[i][j] == 'E')
				map->n_exit++;
			if (map->land[i][j] == 'C')
				map->n_trinkets++;
			j++;
		}
		i++;
	}
}

static	t_player	*construct_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof (t_player));
	if (!player)
		return (NULL);
	player->x = map->x;
	player->y = map->y;
	return (player);
}

static	t_exit	*construct_exit(t_map *map)
{
	t_exit	*exit;
	int		i;
	int		j;

	exit = malloc(sizeof (t_exit));
	if (!exit)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns && map->land[i][j] != '\0')
		{
			if (map->land[i][j] == 'E')
			{
				exit->x = j;
				exit->y = i;
				exit->status = false;
			}
			j++;
		}
		i++;
	}
	return (exit);
}

t_map	*construct_map(char *path)
{
	t_map	*map;

	map = ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	rows_columns(map, path);
	if (map->land)
	{
		count_trinkets(map);
		map->player = construct_player(map);
		map->exit = construct_exit(map);
	}
	check_map(map, path);
	return (map);
}
