/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/04 16:59:57 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/libft/includes/libft.h"
#include "../libs/minilibx-linux/mlx.h"

#include <limits.h>
#include <stdio.h>

# define TILE_SIZE 32

typedef struct t_window_data
{
	int		*mlx_ptr;
	int		*w_ptr;
	int		width;
	int		height;
	char	*w_title;
} 	t_wdata;

typedef struct t_map_data
{
	int		col_nb;
	int		row_nb;
	char	**split;
}	t_mdata;


void	error_exit(t_wdata *window, char *errmsg);
t_wdata	*window_init(int *mlx_ptr, int width, int height, char *title);
void	draw_map(t_wdata *window);

#endif