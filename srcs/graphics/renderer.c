/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 11:17:33 by lgervet          ###   ########.fr       */
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
		while (m->map[y][x])
		{
			if (m->map[y][x] != '1')
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->floor.ptr, \
				x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(w->mlx_ptr, w->w_ptr, a->wall.ptr, \
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void	_render_exit(t_game g, int x, int y)
{
	mlx_put_image_to_window(g.w->mlx_ptr, g.w->w_ptr, g.a->exit.ptr, \
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	_render_collectible(t_game g, int x, int y)
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

void	render_map(t_game *g)
{
	int			y;
	int			x;

	_render_floor_walls(g->w, g->m, g->a);
	y = 0;
	while (g->m->map[y])
	{
		x = 0;
		while (g->m->map[y][x])
		{
			if (g->m->map[y][x] == 'P')
				render_player(g, x, y);
			else if (g->m->map[y][x] == 'C')
				_render_collectible(*g, x, y);
			else if (g->m->map[y][x] == 'E')
				_render_exit(*g, x, y);

			x++;
		}
		y++ ;
	}
	return ;
}
