/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/06 14:35:27 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define TILE_SIZE 32

typedef struct t_window_data
{
	int		*mlx_ptr;
	int		*w_ptr;
	int		width;
	int		height;
	char	*w_title;
}	t_wdata;

typedef struct t_map_data
{
	int		col_nb;
	int		row_nb;
	char	**map;
	char	**d_map;
}	t_mdata;

void	error_exit(t_wdata *window, t_mdata *mdata, char *errmsg);
t_mdata	*parse_file(char *arg);
int		valid_map(t_mdata *mdata);
int		valid_path(t_mdata *mdata);
t_wdata	*window_init(t_mdata *mdata, int *mlx, char *title);
void	render_map(t_wdata *wdata, t_mdata *mdata);
int		create_trgb(int t, int r, int g, int b);

#endif