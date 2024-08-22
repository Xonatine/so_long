/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:11 by frlorenz          #+#    #+#             */
/*   Updated: 2024/08/22 11:55:50 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PJ_DOWN "./textures/Mouse_Down.png"
# define PJ_UP "./textures/Mouse_Up.png"
# define PJ_LEFT "./textures/Mouse_Left.png"
# define PJ_RIGHT "./textures/Mouse_Right.png"
# define BOX   "./textures/Box.png"
# define TRINKET "./textures/Tomato.png"
# define EXIT "./textures/Door_Golden.png"
# define FLOOR "./textures/Grass_Texture.png"

# define WIDTH 128
# define HEIGHT 128

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_exit
{
	int		x;
	int		y;
	bool	status;
}	t_exit;

typedef struct s_map
{
	t_player	*player;
	char		**land;
	bool		error;
	int			rows;
	int			columns;
	int			n_trinkets;
	int			n_players;
	int			x;
	int			y;
	int			n_exit;
	t_exit		*exit;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;

}	t_img;

typedef struct s_game
{
	mlx_t		*mlx;
	int			movements;
	t_map		*map;
	mlx_image_t	*pl_up;
	mlx_image_t	*pl_dw;
	mlx_image_t	*pl_rg;
	mlx_image_t	*pl_lf;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*trinket;
}	t_game;

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memset_gnl(void *b, int c, size_t len);
void	*ft_calloc_gnl(size_t count, size_t len);
int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	clean_memo(char **stash);
char	**read_map(char *path);
t_map	*construct_map(char *path);
void	check_map(t_map *map, char *path);
void	flood_fill(t_map *map, char *path);
void	print_map(t_map *map, void *mlx, void *mlx_win);
void	free_map(t_map *map);
void	free_game(t_game *game);
void	init_game(t_game *game, t_map *map);
void	print_window(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_rigth(t_game *game);
void	collect_trinkets(t_map *map, mlx_image_t *trinket, mlx_image_t *img_p);
void	open_exit(t_map *map, mlx_image_t *img_p, mlx_t *mlx);

#endif
