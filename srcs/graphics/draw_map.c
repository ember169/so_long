/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/05 14:48:26 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_draw_tile(t_wdata *wdata, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_pixel_put(wdata->mlx_ptr, wdata->w_ptr, \
			(x_start * TILE_SIZE) + x, (y_start * TILE_SIZE) + y, color);
			x++;
		}
		y++;
	}
}

void	render_map(t_wdata *wdata, t_mdata *mdata)
{
	int	y;
	int	x;

	y = 0;
	while (mdata->map[y])
	{
		x = 0;
		while (mdata->map[y][x])
		{
			if (mdata->map[y][x] == '1')
				_draw_tile(wdata, x, y, 0x000000);
			else if (mdata->map[y][x] == '0')
				_draw_tile(wdata, x, y, 0xFFFFFF);
			else if (mdata->map[y][x] == 'P')
				_draw_tile(wdata, x, y, 0x551606);
			else if (mdata->map[y][x] == 'C')
				_draw_tile(wdata, x, y, 0xFFA500);
			else if (mdata->map[y][x] == 'E')
				_draw_tile(wdata, x, y, 0x013220);
			x++;
		}
		y++ ;
	}
	return ;
}
