/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:13:07 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 11:16:53 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	_render_floor(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->w->mlx_ptr, g->w->w_ptr, g->a->floor.ptr, \
	x * TILE_SIZE, y * TILE_SIZE);
}

static void	_move_up(t_game *g)
{
	if (g->player_pos.y > 0 \
		&& g->m->map[g->player_pos.y - 1][g->player_pos.x]	!= '1')
	{
		_render_floor(g, g->player_pos.x, g->player_pos.y);
		render_player(g, g->player_pos.x, g->player_pos.y + 1);
		g->moves++;
		update_counter(g);
	}
	return ;
}

static void	_move_down(t_game *g)
{
	if (g->player_pos.y < g->m->row_nb \
		&& g->m->map[g->player_pos.y + 1][g->player_pos.x] != '1')
	{
		_render_floor(g, g->player_pos.x, g->player_pos.y);
		render_player(g, g->player_pos.x, g->player_pos.y + 1);
		g->moves++;
		update_counter(g);
	}
	return ;
}

static void	_move_left(t_game *g)
{
	if (g->player_pos.x > 0 \
		&& g->m->map[g->player_pos.y][g->player_pos.x - 1] != '1')
	{
		_render_floor(g, g->player_pos.x, g->player_pos.y);
		render_player(g, g->player_pos.x - 1, g->player_pos.y);
		g->moves++;
		update_counter(g);
	}
	return ;
}

static void	_move_right(t_game *g)
{
	if (g->player_pos.x < g->m->col_nb \
		&& g->m->map[g->player_pos.y][g->player_pos.x + 1] != '1')
	{
		_render_floor(g, g->player_pos.x, g->player_pos.y);
		render_player(g, g->player_pos.x + 1, g->player_pos.y);
		g->moves++;
		update_counter(g);
	}
	return ;
}

void	move_char(int key, t_game *g)
{
	if (key == UP_W)
		_move_up(g);
	if (key == DOWN_S)
		_move_down(g);
	if (key == LEFT_A)
		_move_left(g);
	if (key == RIGHT_D)
		_move_right(g);
}
