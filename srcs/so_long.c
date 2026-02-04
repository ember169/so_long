/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/04 17:00:39 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
	int		*mlx_ptr;
	t_wdata *window_data;
	t_mdata *map_data;

	if (ac != 1)
		return (0);
	manage_argument(av[1], map_data);

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		write(2, "[!] Couldn't initialize library", 32);
		return (0);
	}
	window_data = window_init(mlx_ptr, "Test #1", 11, 6);
	render_map(window_data, mlx_ptr);
	return (1);
}
