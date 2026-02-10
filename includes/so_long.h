/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 21:15:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define TILE_SIZE 	64
# define UP_W		119
# define DOWN_S		115
# define RIGHT_D	100
# define LEFT_A		97
# define ESC_LNX	65307
# define ESC_MAC	53

typedef struct s_window_data
{
	void	*mlx_ptr;
	void	*w_ptr;
	int		width;
	int		height;
	char	*w_title;
}	t_wdata;

typedef struct s_map_data
{
	int		col_nb;
	int		row_nb;
	char	**map;
	char	**d_map;
}	t_mdata;

typedef struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	
}	t_img;

typedef struct s_assets
{
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collect;
	t_img	exit;
}	t_assets;

typedef struct s_game
{
	t_wdata			*w;
	t_mdata			*m;
	t_assets		*a;
	int				moves;
}	t_game;


void		free_all(t_wdata *window, t_mdata *mdata, t_assets *assets);
void		error_exit(t_wdata *window, t_mdata *mdata, t_assets *assets, char *errmsg);
t_mdata		*parse_file(char *arg);
int			valid_map(t_mdata *mdata);
int			valid_path(t_mdata *mdata);
t_wdata		*window_init(t_mdata *mdata, int *mlx, char *title);
t_assets	*init_assets(t_wdata *wdata, t_mdata *mdata);
void		render_map(t_wdata *wdata, t_mdata *mdata, t_assets *assets);
int			create_trgb(int t, int r, int g, int b);
void		main_mlx_loop(t_game *g);
void	move_char(int key, t_game *g);

#endif