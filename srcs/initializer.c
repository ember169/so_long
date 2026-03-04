/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/03/04 17:38:53 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** init_map_render:
**     First render of the map: floor and walls, then player starting point, 
**     finally collectibles and exit point
**
**     @param *g  Pointer to super-structure t_game
*/
void	init_map_render(t_game *g)
{
	int	y;
	int	x;

	render_floor_walls(g->w, g->m, g->a);
	y = 0;
	while (g->m->map[y])
	{
		x = 0;
		while (g->m->map[y][x])
		{
			if (g->m->map[y][x] == 'P')
				render_player(g, x, y);
			else if (g->m->map[y][x] == 'C')
				render_collectible(*g, x, y);
			else if (g->m->map[y][x] == 'E')
				render_exit(g, x, y);
			x++;
		}
		y++ ;
	}
}

static t_img	_load_texture(t_wdata *w, t_mdata *m, t_assets *a, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(w->mlx_ptr, path, &img.width, \
		&img.height);
	if (!img.ptr)
		error_exit(w, m, a, "[!] Init Error: couldnt load texture\n");
	return (img);
}

/*
** init_assets:
**     Initializes assets and loads textures
**
**     @param  *w  pointer to t_wdata structure
**     @param  *m  pointer to t_mdata structure
**     @return *a  pointer to new structure
*/
t_assets	*init_assets(t_wdata *w, t_mdata *m)
{
	t_assets	*a;

	a = malloc(sizeof(t_assets));
	if (!a)
		error_exit(w, m, NULL, "[!] Init Error: couldnt init assets\n");
	ft_bzero(a, sizeof(t_assets));
	a->player = _load_texture(w, m, a, "assets/player_64.xpm");
	a->wall = _load_texture(w, m, a, "assets/wall_64.xpm");
	a->floor = _load_texture(w, m, a, "assets/floor_64.xpm");
	a->exit = _load_texture(w, m, a, "assets/exit_64.xpm");
	a->collect = _load_texture(w, m, a, "assets/chest_64.xpm");
	return (a);
}

/*
** init_wdata:
**     Initialize t_wdata structure
**
**     @param  *m       pointer to t_mdata structure
**     @param  *mlx     pointer to mlx_pointer
**     @param  *title   future window title
**     @return *w		pointer to new structure
*/
t_wdata	*init_wdata(t_mdata *m, int *mlx, char *title)
{
	t_wdata	*w;
	int		screen_width;
	int		screen_height;

	if (!mlx)
		error_exit(NULL, m, NULL, "[!] Init Error: MLX not initialized\n");
	w = (t_wdata *)malloc(sizeof(t_wdata));
	if (!w)
		error_exit(w, m, NULL, "[!] Init Error: couldnt init t_wdata\n");
	ft_bzero(w, sizeof(t_wdata));
	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	w->width = m->col_nb * TILE_SIZE;
	w->height = m->row_nb * TILE_SIZE;
	w->w_title = title;
	w->mlx_ptr = mlx;
	w->w_ptr = mlx_new_window(w->mlx_ptr, w->width, \
		w->height, w->w_title);
	if (!w->w_ptr)
		error_exit(w, m, NULL, "[!] Init Error: couldnt init w->w_ptr\n");
	if (screen_width < w->width || screen_height < w->height)
		error_exit(w, m, NULL, "[!] Init Error: map doesnt fit screen\n");
	return (w);
}

/*
** init_mdata:
**     Initialize t_mdata structure
**
**     @param  *file_path  path to map file.
**     @return *m 		   pointer to new structure.
*/
t_mdata	*init_mdata(char *file_path)
{
	t_mdata	*m;
	int		count;

	m = (t_mdata *)ft_calloc(1, sizeof(t_mdata));
	if (!m)
		error_exit(NULL, NULL, NULL, "[!] Init Error: couldnt init t_mdata\n");
	m->c_nb = count_file_collectibles(file_path);
	if (m->c_nb < 0)
		error_exit(NULL, m, NULL, "[!] Init Error: couldnt open file\n");
	if (m->c_nb < 1)
		error_exit(NULL, m, NULL, "[!] Init Error: found 0 collectibles\n");
	m->c_array = ft_calloc(m->c_nb, sizeof(t_collect));
	if (!m->c_array)
		error_exit(NULL, m, NULL, "[!] Init Error: couldnt init m->c_array\n");
	count = count_file_lines(file_path);
	m->map = ft_calloc(count + 1, sizeof(char *));
	if (!m->map)
		error_exit(NULL, m, NULL, "[!] Init Error: couldnt init m->map\n");
	m->d_map = ft_calloc(count + 1, sizeof(char *));
	if (!m->d_map)
		error_exit(NULL, m, NULL, "[!] Init Error: couldnt init m->d_map\n");
	return (m);
}
