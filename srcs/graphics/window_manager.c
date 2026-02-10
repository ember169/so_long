/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/09 14:17:13 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_wdata	*window_init(t_mdata *mdata, int *mlx, char *title)
{
	t_wdata	*window;

	window = (t_wdata *)malloc(sizeof(t_wdata));
	if (!window)
		error_exit(window, mdata, NULL, "[!] Error initalizing t_wdata\n");
	window->mlx_ptr = NULL;
	window->w_ptr = NULL;
	window->w_title = NULL;
	window->width = mdata->col_nb * TILE_SIZE;
	window->height = mdata->row_nb * TILE_SIZE;
	window->w_title = title;
	window->mlx_ptr = mlx;
	window->w_ptr = mlx_new_window(window->mlx_ptr, window->width, \
		window->height, window->w_title);
	if (!window->w_ptr)
		error_exit(window, mdata, NULL, "[!] Error initalizing window->w_ptr\n");
	return (window);
}
