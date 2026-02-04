/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/04 17:03:01 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_wdata	*window_init(int *mlx_ptr, char *title, int col_nb, int row_nb)
{
	t_wdata *window;

	window = (t_wdata *)malloc(sizeof(t_wdata));
	if (!window)
		error_exit(window, NULL);
	window->mlx_ptr = NULL;
	window->w_ptr = NULL;
	window->w_title = NULL;
	window->width = col_nb * TILE_SIZE;
	window->height = row_nb * TILE_SIZE;
	window->w_title = title;
	window->mlx_ptr = mlx_ptr;
	window->w_ptr = mlx_new_window(window->mlx_ptr, window->width,\
		window->height, window->w_title);
	if (!window->w_ptr)
		error_exit(window, "[!] Couldn't initialize window\n");
	return (window);
}

t_wdata *render_map(t_wdata *window, int *mlx_ptr)
{
	draw_map(window);
	mlx_loop(window->mlx_ptr);
	return (window);
}
