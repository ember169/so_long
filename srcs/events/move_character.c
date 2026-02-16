/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:13:07 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 16:12:24 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** check_pos:
**     Checks current position : if on E and has all collected or is on C 
**
**     @param *g  	   game struct
**     @param next_x   future x pos
**	   @param next_y.  future y pos
*/
void	check_pos(t_game *g, int next_x, int next_y)
{
	if (g->m->map[next_y][next_x] == 'E')
	{
		if (g->collected == g->m->c_nb)
		{
			render_floor(g, g->player_pos.x, g->player_pos.y);
			render_player(g, next_x, next_y);
			def_exit(g->w, g->m, g->a, "> Congrats, you won the map.\n");
		}
	}
	if (g->m->map[g->player_pos.y][g->player_pos.x] == 'E')
		render_exit(g, g->player_pos.x, g->player_pos.y);
	else
		render_floor(g, g->player_pos.x, g->player_pos.y);
}

void	move_up(t_game *g)
{
	if (g->player_pos.y > 0 && g->m->map[g->player_pos.y - 1][g->player_pos.x]\
		 != '1')
	{
		check_pos(g, g->player_pos.x, g->player_pos.y - 1);
		render_player(g, g->player_pos.x, g->player_pos.y - 1);
		g->moves++;
		ft_printf("> Movements: %d\n", g->moves);
	}
	return ;
}

void	move_down(t_game *g)
{
	if (g->player_pos.y < g->m->row_nb \
		&& g->m->map[g->player_pos.y + 1][g->player_pos.x] != '1')
	{
		check_pos(g, g->player_pos.x, g->player_pos.y + 1);
		render_player(g, g->player_pos.x, g->player_pos.y + 1);
		g->moves++;
		ft_printf("> Movements: %d\n", g->moves);
	}
	return ;
}

void	move_left(t_game *g)
{
	if (g->player_pos.x > 0 \
		&& g->m->map[g->player_pos.y][g->player_pos.x - 1] != '1')
	{
		check_pos(g, g->player_pos.x - 1, g->player_pos.y);
		render_player(g, g->player_pos.x - 1, g->player_pos.y);
		g->moves++;
		ft_printf("> Movements: %d\n", g->moves);
	}
	return ;
}

void	move_right(t_game *g)
{
	if (g->player_pos.x < g->m->col_nb \
		&& g->m->map[g->player_pos.y][g->player_pos.x + 1] != '1')
	{
		check_pos(g, g->player_pos.x + 1, g->player_pos.y);
		render_player(g, g->player_pos.x + 1, g->player_pos.y);
		g->moves++;
		ft_printf("> Movements: %d\n", g->moves);
	}
	return ;
}
