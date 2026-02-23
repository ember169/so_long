/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:27:56 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/23 14:46:59 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** flood_fill:
**     Recursively fills the entire map with 'V'. Begins with current coords
**	   and spreads to adjacent ones. Ends only if is a wall or already Visited
**
**     @param *m  	   struct map data
**     @param y  	   player starting point y coordinate
**     @param x  	   player starting point x coordinate
*/
void	flood_fill(t_mdata *m, int y, int x)
{
	if (x < 0 || y < 0 || x >= m->col_nb || y >= m->row_nb)
		return ;
	if (m->d_map[y][x] == '1' || m->d_map[y][x] == 'V')
		return ;
	m->d_map[y][x] = 'V';
	flood_fill(m, y + 1, x);
	flood_fill(m, y - 1, x);
	flood_fill(m, y, x + 1);
	flood_fill(m, y, x - 1);
}

/*
** _check_path_found:
**     Checks if there is still non replaced E and C
**
**     @param *m  	   struct map data
**	   @returns		   1 if no remaining E/C | 0 if yes
*/
int	_check_path_found(t_mdata *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if ((m->map[i][j] == 'C' || m->map[i][j] == 'E')
				&& m->d_map[i][j] != 'V')
			{
				ft_printf("Fail at [%d][%d]: expected C or E to be V\n", i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
** _find_player_pos:
**     Gets  player starting point coordinates
**
**     @param *m  	   struct map data
**     @param *y  	   pointer to coordinate
**     @param *x  	   pointer to coordinate
*/
void	_find_player_pos(t_mdata *m, int *y, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (m->d_map[i])
	{
		j = 0;
		while (m->d_map[i][j])
		{
			if (m->d_map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

/*
** valid_path:
**     Uses player coordinates to flood-fill map and determines if map is 
**	   winnable
**
**     @param *m  pointer to structure t_mdata
**     @return 1 if valid / 0 if not
*/
int	valid_path(t_mdata *m)
{
	int	y;
	int	x;
	int	res;

	x = 0;
	y = 0;
	_find_player_pos(m, &y, &x);
	flood_fill(m, y, x);
	res = _check_path_found(m);
	return (res);
}
