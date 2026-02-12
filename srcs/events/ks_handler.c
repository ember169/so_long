/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ks_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:02:20 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 10:49:46 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_counter(t_game *g)
{
	ft_printf("Movements: %d\n", g->moves);
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
	mlx_hook(g->w->w_ptr, 03, 1L<<1, &handle_key_release, g);
	mlx_loop(g->w->mlx_ptr);
}
