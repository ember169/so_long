/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:27:17 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 14:21:43 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_window_data
{
	void	*mlx_ptr;
	void	*w_ptr;
	int		width;
	int		height;
	char	*w_title;
}	t_wdata;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_collectible
{
	int		uid;
	t_pos	pos;
	int		collected;
}	t_collect;


typedef struct s_map_data
{
	int				col_nb;
	int				row_nb;
	int				c_nb;
	t_collect		**c_array;
	char			**map;
	char			**d_map;
}	t_mdata;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_assets
{
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collect;
	t_img	exit;
}	t_assets;

typedef struct s_game
{
	t_wdata			*w;
	t_mdata			*m;
	t_assets		*a;
	t_pos			player_pos;
	int				collected;
	int				moves;
}	t_game;

#endif