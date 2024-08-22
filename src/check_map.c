/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:49 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 12:07:23 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	void	check_char(t_map *map)
{
	int			i;
	int			j;
	const char	*str;

	str = "1PCE0";
	i = 0;
	if (map->error != false)
	{
		while (map->land[i] && map->error != false)
		{
			j = 0;
			while (j <= map->columns && map->error != false)
			{
				if (!ft_strchr(str, map->land[i][j]))
				{
					ft_printf("Error\nMapa no valido\n");
					map->error = false;
				}
				j++;
			}
			i++;
		}
	}
}

static	void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->rows && map->error != false)
	{
		if (i > 0 && i < (map->rows))
		{
			if (map->land[i][0] != '1' || map->land[i][map->columns] != '1')
				map->error = false;
		}
		else
		{
			j = 0;
			while (j <= map->columns && map->error != false)
			{
				if (!ft_strchr("1", map->land[i][j]))
					map->error = false;
				j++;
			}
		}
		i++;
	}
}

static	void	check_outline(t_map *map)
{
	int	i;

	i = 1;
	if (map->error != false)
	{
		while (i < map->rows && map->error != false)
		{
			if (((ft_strlen(map->land[i]) - 2) != map->columns))
			{
				ft_printf("Error\nMapa no valido\n");
				map->error = false;
			}
			else if (((ft_strlen(map->land[map->rows]) - 1) != map->columns))
			{
				ft_printf("Error\nMapa no valido\n");
				map->error = false;
			}
			i++;
		}
	}
}

void	check_map(t_map *map, char *path)
{
	if (map-> error != false)
	{
		if (map->n_players != 1 || map->n_exit != 1 || map->n_trinkets < 1)
		{
			ft_printf("Error\nMapa no valido\n");
			map->error = false;
		}
		check_char(map);
		if (map->error != false)
		{
			check_walls(map);
			if (map->error == false)
				ft_printf("Error\nMapa no valido\n");
		}
		check_outline(map);
		flood_fill(map, path);
	}
}
