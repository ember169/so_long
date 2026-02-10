/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 21:04:06 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	void		*mlx_ptr;
	t_game		game;

	if (ac != 2)
		return (0);
	ft_bzero(&game, sizeof(t_game));
	game.m = parse_file(av[1]);
	if (!game.m || !valid_map(game.m))
		error_exit(NULL, game.m, NULL, "[!] Invalid map\n");
	ft_printf("[x] Mapped parsed\n");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		error_exit(NULL, game.m, NULL, "[!] Couldn't init MLX\n");
	ft_printf("[x] MLX initialized\n");
	game.w = window_init(game.m, mlx_ptr, "so_long");
	game.a = init_assets(game.w, game.m);
	ft_printf("[x] Window & assets initialized\n");
	render_map(game.w, game.m, game.a);
	ft_printf("[x] Map rendered\n");
	main_mlx_loop(&game);
	return (1);
}
