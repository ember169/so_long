/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 12:06:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

static void	_free_assets(t_wdata *window, t_assets *assets)
{
	if (assets->collect.ptr)
		mlx_destroy_image(window->mlx_ptr, assets->collect.ptr);
	if (assets->floor.ptr)
		mlx_destroy_image(window->mlx_ptr, assets->floor.ptr);
	if (assets->exit.ptr)
		mlx_destroy_image(window->mlx_ptr, assets->exit.ptr);
	if (assets->wall.ptr)
		mlx_destroy_image(window->mlx_ptr, assets->wall.ptr);
	if (assets->player.ptr)
		mlx_destroy_image(window->mlx_ptr, assets->player.ptr);
	free(assets);
}

void	free_all(t_wdata *window, t_mdata *mdata, t_assets *assets)
{
	if (assets)
		_free_assets(window, assets);
	if (mdata)
		_free_map(mdata);
	if (window)
		_free_window(window);
}

