/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:13:07 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 21:35:34 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	_move_up(t_game *g)
{
	
}

static void	_move_down(t_game *g)
{

}

static void	_move_left(t_game *g)
{

}

static void	_move_right(t_game *g)
{
	
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
	g->moves++;
}