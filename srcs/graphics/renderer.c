/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 11:21:02 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	_render_floor_walls(t_wdata *w, t_mdata *m, t_assets *a)
{
	int			y;
	int			x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while(m->map[y][x])
		{
			if (m->map[y][x] != '1')
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->floor.ptr,\
				 	x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->wall.ptr,\
				 	x * TILE_SIZE, y * TILE_SIZE);				
			x++;
		}
		y++;
	}
}

void	render_map(t_wdata *w, t_mdata *m, t_assets *a)
{
	int			y;
	int			x;

	_render_floor_walls(w, m, a);
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->player.ptr,\
					 x * TILE_SIZE, y * TILE_SIZE);
			else if (m->map[y][x] == 'C')
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->collect.ptr,\
					 x * TILE_SIZE, y * TILE_SIZE);
			else if (m->map[y][x] == 'E')
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->exit.ptr,\
					 x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++ ;
	}
	return ;
}
