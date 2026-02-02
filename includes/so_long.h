/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/01 12:26:34 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/libft/includes/libft.h"
#include "../libs/minilibx-linux/mlx.h"

#include <limits.h>

typedef struct t_window_data
{
	int		*mlx_ptr;
	int		*w_ptr;
	int		width;
	int		height;
	char	*w_title;
} 	t_wdata;

void	error_exit(t_wdata *window, char *errmsg);

#endif