/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/05 13:14:28 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int		*mlx_ptr;
	t_wdata	*window_data;
	t_mdata	*map_data;

	if (ac != 2)
		return (0);
	ft_printf("[ ] Parsing file\n");
	map_data = parse_file(av[1]);
	ft_printf("[x] File parsed\n");
	// if (!valid_map(map_data))
	// 	error_exit(NULL, map_data, "[!] Invalid map\n");
	ft_printf("[ ] Initializing MLX\n");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		write(2, "[!] Couldn't initialize library", 32);
		return (0);
	}
	ft_printf("[x] MLX initialized\n");
	ft_printf("[ ] Spawning window\n");
	window_data = window_init(map_data, mlx_ptr, "Test #1");
	ft_printf("[x] Window initialized\n");
	ft_printf("[ ] Rendering map\n");
	render_map(window_data, map_data);
	ft_printf("[x] Map rendered\n");
	mlx_loop(window_data->mlx_ptr);
	return (1);
}
