/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:10:16 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 11:50:32 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	void	fill_map(char **land, int x, int y, t_map *m)
{
	if (m->x != x || m->y != y)
	{
		if (land[y][x] == '1' || land[y][x] == 'P')
			return ;
		land[y][x] = 'P';
		fill_map(land, x, (y - 1), m);
		fill_map(land, (x + 1), y, m);
		fill_map(land, x, (y + 1), m);
		fill_map(land, (x - 1), y, m);
	}
	else
	{
		fill_map(land, x, (y - 1), m);
		fill_map(land, (x + 1), y, m);
		fill_map(land, x, (y + 1), m);
		fill_map(land, (x - 1), y, m);
	}
	return ;
}

void	check_solution(char **copy_land, t_map *map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (copy_land[i])
	{
		j = 0;
		while (copy_land[i][j])
		{
			if (copy_land[i][j] == 'C' || copy_land[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 0)
	{
		ft_printf("Error\nMapa no valido\n");
		map->error = false;
	}
}

void	flood_fill(t_map *map, char *path)
{
	char	**fill;
	int		i;

	i = 0;
	if (map->error != false)
	{
		fill = read_map(path);
		fill_map(fill, map->x, map->y, map);
		check_solution(fill, map);
		i = 0;
		while (fill[i])
		{
			free (fill[i]);
			i++;
		}
		free (fill);
	}
}
