/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:09:13 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 11:46:24 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_img	_load_texture(t_wdata *w, t_mdata *m, t_assets *a, char *path)
{
	t_img	img;


	img.ptr = mlx_xpm_file_to_image(w->mlx_ptr,\
		 path, &img.width, &img.height);
	if (!img.ptr)
		error_exit(w, m, a, "[!] Error loading texture\n");
	return (img);
}

t_assets	*init_assets(t_wdata *w, t_mdata *m)
{
	t_assets	*assets;
	
	assets = malloc(sizeof(t_assets));
	if (!assets)
		error_exit(w, m, NULL, "[!] Error initializing assets\n");
	ft_bzero(assets, sizeof(assets));
	assets->player = _load_texture(w, m, assets, "assets/player_final.xpm");
	assets->wall = _load_texture(w, m, assets, "assets/wall_64.xpm");
	assets->floor = _load_texture(w, m, assets, "assets/floor_64.xpm");
	assets->exit = _load_texture(w, m, assets, "assets/exit_64.xpm");
	assets->collect = _load_texture(w, m, assets, "assets/chest_64.xpm");
	return (assets);
}
