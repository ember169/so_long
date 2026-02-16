/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:35:26 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 15:10:59 by lgervet          ###   ########.fr       */
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

static t_collect	*_add_collectible(t_mdata *mdata, int x, int y, int i)
{
	t_collect	*new_chest;

	new_chest = ft_calloc(1, sizeof(t_collect));
	if (!new_chest)
		error_exit(NULL, mdata, NULL, "[!] Error adding collectible\n");
	new_chest->uid = i;
	new_chest->pos.x = x;
	new_chest->pos.y = y;
	ft_printf("[ ] Adding chest #%d to entities [%d] @ %d:%d\n", \
		new_chest->uid, (i - 1), new_chest->pos.x, new_chest->pos.y);
	return (new_chest);
}

/*
** _duplicate_map:
**     Duplicates the map in its own struct child + replaces 'P' with 'V'
**
**     @param mdata  map struct
**     @return pointer toward struct
*/
static t_mdata	*_duplicate_map(t_mdata *m)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (m->map[y])
	{
		m->d_map[y] = ft_calloc((ft_strlen(m->map[y]) + 1),	sizeof(char));
		if (!m->d_map[y])
			error_exit(NULL, m, NULL, "[!] Error initializing d_map[y]");
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'C' && i++ <= m->c_nb)
				m->c_array[i - 1] = _add_collectible(m, x, y, i);
			if (m->map[y][x] == 'P')
				m->d_map[y][x] = 'V';
			else
				m->d_map[y][x] = m->map[y][x];
			x++;
		}
		y++;
	}
	return (m);
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
