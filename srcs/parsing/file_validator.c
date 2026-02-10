/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:35:26 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 10:48:48 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** _valid_borders:
**     Checks first and last rows then left and right columns for walls ('1').
**
**     @param mdata  map struct
**     @return 1 if valid / 0 if not
*/
static int	_valid_borders(t_mdata *mdata)
{
	int	i;

	i = 0;
	while (i < mdata->col_nb)
	{
		if (mdata->map[0][i] != '1' || mdata->map[mdata->row_nb - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < mdata->row_nb - 1)
	{
		if (mdata->map[i][0] != '1' || mdata->map[i][mdata->col_nb - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*
** _duplicate_map:
**     Duplicates the map in its own struct child + replaces 'P' with 'V'
**
**     @param mdata  map struct
**     @return pointer toward struct
*/
static t_mdata	*_duplicate_map(t_mdata *mdata)
{
	int	x;
	int	y;

	y = 0;
	while (mdata->map[y])
	{
		mdata->d_map[y] = malloc(ft_strlen(mdata->map[y]) * sizeof(char));
			if (!mdata->d_map[y])
				error_exit(NULL, mdata, NULL, "[!] Error initializing mdata->d_map[y]");
		x = 0;
		while (mdata->map[y][x])
		{
			if (mdata->map[y][x] == 'P')
				mdata->d_map[y][x] = 'V';
			else
				mdata->d_map[y][x] = mdata->map[y][x];
			x++;
		}
		y++;
	}
	return (mdata);
}

int	valid_map(t_mdata *mdata)
{
	if (!(_valid_borders(mdata)))
		return (0);
	ft_printf("[x] Map borders checked\n");
	if (!valid_path(_duplicate_map(mdata)))
		return (0);
	ft_printf("[x] Path checked\n");
	return (1);
}
