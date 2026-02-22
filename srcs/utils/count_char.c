/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:53:16 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/22 19:35:45 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	valid_char_nb(t_mdata *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] != '1' && m->map[y][x] != '0'\
				&& m->map[y][x] != 'C' && m->map[y][x] != 'E'\
				&& m->map[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	_print_map(t_mdata *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->d_map[y])
	{
		x = 0;
		while (m->d_map[y][x])
		{
			ft_printf("%c", m->d_map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
