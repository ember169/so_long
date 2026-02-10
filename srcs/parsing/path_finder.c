/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:34:36 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 10:48:25 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** _all_replaced:
**     Checks entire map for remaining characters
**
**     @param mdata  map struct
**     @return 1 if everything has been replaced / 0 if 'C' or 'O' remaining
*/
static int	_all_replaced(t_mdata *mdata)
{
	int	x;
	int	y;

	y = 0;
	while (mdata->d_map[y])
	{
		x = 0;
		while (mdata->d_map[y][x])
		{
			if (mdata->d_map[y][x] != 'V' && mdata->d_map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
** _replace_neighbours:
**     Replaces top bottom left and right grid neighbours char by 'V' if not '1'
**
**     @param mdata  map struct
**     @param y  	 coordinate (row number)
**     @param y  	 coordinate (col number)
**     @return number of replaced chars
*/
static int	_fill(t_mdata *mdata, int y, int x)
{
	if (mdata->d_map[y][x] != '1' && mdata->d_map[y][x] != 'V')
	{
		mdata->d_map[y][x] = 'V';
		return (1);
	}
	return (0);
}

static int	_replace_neighbours(t_mdata *mdata, int y, int x)
{
	int	n;

	n = 0;
	n += _fill(mdata, y, x + 1);
	n += _fill(mdata, y, x - 1);
	n += _fill(mdata, y + 1, x);
	n += _fill(mdata, y - 1, x);
	return (n);
}

/*
** _replace_loop:
**     Loops through the map seeking 'V' and asks to replace neighbours
**
**     @param mdata  map struct
**     @return number of replaced characters per iteration
*/
static int	_replace_loop(t_mdata *mdata)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	y = 0;
	while (mdata->d_map[y])
	{
		x = 0;
		while (mdata->d_map[y][x])
		{
			if (mdata->d_map[y][x] == 'V')
				n += _replace_neighbours(mdata, y, x);
			x++;
		}
		y++;
	}
	return (n);
}

int	valid_path(t_mdata *mdata)
{
	int	i;

	i = 0;
	while (i < (mdata->col_nb * mdata->row_nb))
	{
		if(!(_replace_loop(mdata)))
			break ;
		i++;
	}
	if (!(_all_replaced(mdata)))
		return (0);
	return (1);
}
