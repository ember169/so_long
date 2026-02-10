/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:02:20 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 21:32:52 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	_update_counter(t_game *g)
{
	ft_printf("Movements: %d\n", g->moves);
}

static int	handle_key_release(int key, t_game *g)
{
	int	tmp;

	tmp = g->moves;
	if (key == ESC_MAC || key == ESC_LNX)
        error_exit(g->w, g->m, g->a, "[i] Escaping...");
	if (key == UP_W || key == DOWN_S || key == LEFT_A || key == RIGHT_D)
		move_char(key, g);
	if (g->moves > tmp)
		update_counter(g);
	return (0);
}

void	main_mlx_loop(t_game *g)
{
	mlx_hook(g->w->w_ptr, 03, 1L<<1, &handle_key_release, g);
	mlx_loop(g->w->mlx_ptr);
}
