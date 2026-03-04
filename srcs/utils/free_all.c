/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/03/04 17:40:15 by lgervet          ###   ########.fr       */
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
	if (mdata->c_array)
	{
		i = 0;
		while (mdata->c_array[i])
			free(mdata->c_array[i++]);
		free(mdata->c_array);
	}
}

void	free_d_map(t_mdata *mdata)
{
	int	i;

	if (!mdata->d_map)
		return ;
	i = 0;
	while (mdata->d_map[i])
		free(mdata->d_map[i++]);
	free(mdata->d_map);
}

static void	_free_window(t_wdata *wdata)
{
	if (wdata->w_ptr)
		mlx_destroy_window(wdata->mlx_ptr, wdata->w_ptr);
	if (wdata->w_ptr)
		mlx_destroy_display(wdata->mlx_ptr);
	free(wdata->mlx_ptr);
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
	if (window->w_ptr)
		mlx_destroy_window(window->mlx_ptr, window->w_ptr);
	free(assets);
}

/*
** free_all:
**     Frees every created structures
**
**     @param *window  pointer to t_wdata
**     @param *mdata   pointer to t_mdata
**     @param *wassets pointer to t_assets
*/
void	free_all(t_wdata *window, t_mdata *mdata, t_assets *assets)
{
	if (assets)
		_free_assets(window, assets);
	if (window)
		_free_window(window);
	if (mdata)
	{
		_free_map(mdata);
		free_d_map(mdata);
		free(mdata);
	}
}
