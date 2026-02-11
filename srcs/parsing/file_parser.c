/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:09:12 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/11 15:12:24 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	trim_newline(char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

static void	_parse_data(t_mdata *map_data, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		map_data->map[i] = get_next_line(fd);
		if (!map_data->map[i])
			break ;
		trim_newline(map_data->map[i]);
		i++;
	}
	map_data->map[i] = NULL;
	map_data->row_nb = i;
	map_data->col_nb = ft_strlen(map_data->map[0]);
}

t_mdata	*parse_file(t_game *game, char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (!fd)
		error_exit(NULL, game->m, NULL, "[!] Error opening file\n");
	_parse_data(game->m, fd);
	close(fd);
	return (game->m);
}
