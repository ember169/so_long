/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:02:20 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 16:09:43 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	_get_chest_index(t_game *g, int x, int y)
{
	int	i;

	i = 0;
	while (g->m->c_array[i])
	{
		if (g->m->c_array[i]->pos.x == x && g->m->c_array[i]->pos.y == y)
			return (i);
		i++;
	}
	return (-1);
}

int	_has_been_collected(t_game *g, int index)
{
	if (g->m->c_array[index]->collected == 1)
			return (1);
	return (0);
}

void	move_char(int key, t_game *g)
{
	int	index;

	if (g->m->map[g->player_pos.y][g->player_pos.x] == 'C')
	{
		index = _get_chest_index(g, g->player_pos.x, g->player_pos.y);
		if (!_has_been_collected(g, index))
		{
			g->collected += 1;
			g->m->c_array[index]->collected = 1;
			ft_printf("> Collected: %d/%d\n", g->collected, g->m->c_nb);
		}
	}
	if (key == UP_W)
		move_up(g);
	if (key == DOWN_S)
		move_down(g);
	if (key == LEFT_A)
		move_left(g);
	if (key == RIGHT_D)
		move_right(g);
}

static int	handle_key_release(int key, t_game *g)
{
	if (key == ESC_MAC || key == ESC_LNX)
		def_exit(g->w, g->m, g->a, "[i] Escaping...\n");
	if (key == UP_W || key == DOWN_S || key == LEFT_A || key == RIGHT_D)
		move_char(key, g);
	return (0);
}

void	main_mlx_loop(t_game *g)
{
	mlx_hook(g->w->w_ptr, 03, 1L << 1, &handle_key_release, g);
	mlx_hook(g->w->w_ptr, 17, 0, &close_button_handler, g);
	mlx_loop(g->w->mlx_ptr);
}
