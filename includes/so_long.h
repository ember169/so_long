/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 12:07:32 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define TILE_SIZE 64

typedef struct s_window_data
{
	int		*mlx_ptr;
	int		*w_ptr;
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
	int	*ptr;
	int	width;
	int	height;
	
}	t_img;

typedef struct s_assets
{
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collect;
	t_img	exit;
}	t_assets;

void		free_all(t_wdata *window, t_mdata *mdata, t_assets *assets);
void		error_exit(t_wdata *window, t_mdata *mdata, t_assets *assets, char *errmsg);
t_mdata		*parse_file(char *arg);
int			valid_map(t_mdata *mdata);
int			valid_path(t_mdata *mdata);
t_wdata		*window_init(t_mdata *mdata, int *mlx, char *title);
t_assets	*init_assets(t_wdata *wdata, t_mdata *mdata);
void		render_map(t_wdata *wdata, t_mdata *mdata, t_assets *assets);
int			create_trgb(int t, int r, int g, int b);

#endif