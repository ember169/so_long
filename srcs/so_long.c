/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/22 17:49:19 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	_initialize_game(t_game *game, char *file_path)
{
	game->m = init_mdata(file_path);
	parse_file(game, file_path);
	if (!game->m)
		error_exit(NULL, NULL, NULL, "[!] game->m is NULL\n");
	if (!valid_map(game->m))
		error_exit(NULL, game->m, NULL, "[!] valid_map failed\n");
	game->w = init_wdata(game->m, mlx_init(), "so_long");
	game->a = init_assets(game->w, game->m);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
		return (0);
	ft_bzero(&game, sizeof(t_game));
	_initialize_game(&game, av[1]);
	init_map_render(&game);
	main_mlx_loop(&game);
	return (1);
}
