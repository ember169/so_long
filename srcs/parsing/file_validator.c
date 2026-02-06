/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:35:26 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/06 10:52:00 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	_first_last_valid(char *first, char *last)
{
	int	i;

	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	_left_right_valid(t_mdata *mdata)
{
	int	i;

	i = 1;
	while (mdata->map[i])
	{
		if (mdata->map[i][0] != '1' || mdata->map[i][mdata->col_nb - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(t_mdata *mdata)
{
	ft_printf("[ ] Checking map borders\n");
	if (!(_first_last_valid(mdata->map[0], mdata->map[mdata->row_nb - 1])))
		return (0);
	if (!(_left_right_valid(mdata)))
		return (0);
	ft_printf("[x] Map borders checked\n");
	return (1);
}
