/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:53:16 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/23 14:34:02 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** valid_chars_legality:
**     Iterate through the map to find illegal characters
**
**     @param *m  pointer to structure t_mdata
**     @return 1 everything is fine / 0 illegal character detected
*/
int	valid_chars_legality(t_mdata *m)
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
