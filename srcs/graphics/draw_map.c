/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/04 17:03:00 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_wall(int i)
{
	
}


void	render_map(t_wdata *window, char **map, t_mdata *map_data)
{
	int	i;
	i = 0;
	while (map[i])
	{
		if (map[i] == '1')
			draw_wall(i);
		else if (map[i] == '0')
			continue ;
		else if (map[i] == 'C')
			draw_collectible(i);
		else if (map[i] == 'E')
			draw_exit(i);
		else if (map[i] == 'P')
			draw_player(i);
		i++ ;
	}
}
