/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:50:16 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/20 16:30:35 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static	int	open_map(char *map)
{
	int		fd;
	int		i;
	char	*path;

	path = "maps/";
	path = ft_strjoin(path, map);
	i = ft_strlen(path) - 4;
	if (ft_strncmp(path + i, ".ber", 4) != 0 || ft_strlen(map) <= 4)
	{
		free (path);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	free (path);
	return (fd);
}

static	char	**buffer_map(char *path)
{
	int		i;
	int		fd;
	char	**map;
	char	*line;

	i = 0;
	fd = open_map(path);
	if (fd == -1)
		return (NULL);
	while (i++ >= 0)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		free (line);
	}
	close (fd);
	map = (char **) ft_calloc(i, sizeof (char **));
	if (!map)
		return (NULL);
	return (map);
}

char	**read_map(char *path)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	map = buffer_map(path);
	if (!map)
		return (NULL);
	fd = open_map(path);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i >= 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = line;
		i++;
	}
	close (fd);
	if (i == 0)
		return (NULL);
	return (map);
}
