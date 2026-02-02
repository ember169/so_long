/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/02 12:54:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_wdata	*window_init(int *mlx_ptr, int width, int height, char *title)
{
	t_wdata *window;

	window = (t_wdata *)malloc(sizeof(t_wdata));
	if (!window)
		error_exit(window, NULL);
	window->mlx_ptr = NULL;
	window->w_ptr = NULL;
	window-> width = 0;
	window->height = 0;
	window->w_title = NULL;
	window->mlx_ptr = mlx_ptr;
	window->width = width;
	window->height = height;
	window->w_title = title;
	window->w_ptr = mlx_new_window(window->mlx_ptr, window->width,\
		window->height, window->w_title);
	if (!window->w_ptr)
		error_exit(window, "[!] Couldn't initialize window\n");
	return (window);
}

int main(void)
{
	int	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		write(2, "[!] Couldn't initialize library", 32);
		return (0);
	}
	window_init(mlx_ptr, 900, 800, "Test #1");
}
