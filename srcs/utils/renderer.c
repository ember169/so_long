/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 15:14:23 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_floor_walls(t_wdata *w, t_mdata *m, t_assets *a)
{
	int			y;
	int			x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
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

void	render_floor(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->w->mlx_ptr, g->w->w_ptr, g->a->floor.ptr, \
	x * TILE_SIZE, y * TILE_SIZE);
}

void	render_exit(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->w->mlx_ptr, g->w->w_ptr, g->a->exit.ptr, \
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_collectible(t_game g, int x, int y)
{
	mlx_put_image_to_window(g.w->mlx_ptr, g.w->w_ptr, g.a->collect.ptr, \
	x * TILE_SIZE, y * TILE_SIZE);
}

void	render_player(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->w->mlx_ptr, g->w->w_ptr, g->a->player.ptr, \
	x * TILE_SIZE, y * TILE_SIZE);
	g->player_pos.x = x;
	g->player_pos.y = y;
}
