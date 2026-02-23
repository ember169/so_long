/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:56:54 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/23 14:46:35 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	_initialize_game(t_game *game, char *file_path)
{
	game->m = init_mdata(file_path);
	parse_file(game, file_path);
	if (!game->m)
		error_exit(NULL, NULL, NULL, "[!] Init Error: couldnt init game->m\n");
	if (!valid_map(game->m))
		error_exit(NULL, game->m, NULL, "[!] Map Error: invalid map \n");
	game->w = init_wdata(game->m, mlx_init(), "so_long");
	game->a = init_assets(game->w, game->m);
}

int	_check_file_ext(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i - 1] == 'r' && s[i - 2] == 'e' \
		&& s[i - 3] == 'b' && s[i - 4] == '.')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2 || !_check_file_ext(av[1]))
		error_exit(NULL, NULL, NULL, "[i] Try: ./so_long <path/to/map.ber>\n");
	ft_bzero(&game, sizeof(t_game));
	_initialize_game(&game, av[1]);
	init_map_render(&game);
	main_mlx_loop(&game);
	return (1);
}
