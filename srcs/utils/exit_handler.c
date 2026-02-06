/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/06 13:35:52 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_free_map(t_mdata *mdata)
{
	int	i;

	if (!mdata)
		return ;
	if (mdata->map)
	{
		i = 0;
		while (mdata->map[i])
			free(mdata->map[i++]);
		free(mdata->map);
	}
	if (mdata->d_map)
	{
		i = 0;
		while (mdata->d_map[i])
			free(mdata->d_map[i++]);
		free(mdata->d_map);
	}
	free(mdata);
}

static void	_free_window(t_wdata *wdata)
{
	if (wdata->w_ptr)
	{
		mlx_clear_window(wdata->mlx_ptr, wdata->w_ptr);
		mlx_destroy_window(wdata->mlx_ptr, wdata->w_ptr);
	}
	free(wdata);
}

static void	print_error(char *msg)
{
	if (!msg)
		msg = "[!] Error\n";
	write(2, msg, ft_strlen(msg));
	return ;
}

void	error_exit(t_wdata *window, t_mdata *mdata, char *errmsg)
{
	print_error(errmsg);
	if (window)
		_free_window(window);
	if (mdata)
		_free_map(mdata);
	print_error("[i] Everything has been properly freed, exiting cleanly\n");
	exit(1);
}
