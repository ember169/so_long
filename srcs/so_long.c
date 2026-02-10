/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 12:05:39 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int			*mlx_ptr;
	t_wdata		*window_data;
	t_mdata		*map_data;
	t_assets	*assets;

	if (ac != 2)
		return (0);
	map_data = parse_file(av[1]);
	ft_printf("[x] File parsed\n");
	if (!valid_map(map_data))
		error_exit(NULL, map_data, NULL, "[!] Invalid map\n");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		error_exit(NULL, map_data, NULL, "[!] Couldn't initialize library\n");
	ft_printf("[x] MLX initialized\n");
	window_data = window_init(map_data, mlx_ptr, "so_long");
	ft_printf("[x] Window initialized\n");
	assets = init_assets(window_data, map_data);
	render_map(window_data, map_data, assets);
	ft_printf("[x] Map rendered\n");
	mlx_loop(window_data->mlx_ptr);
	return (1);
}
