/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:09:12 by lgervet           #+#    #+#             */
/*   Updated: 2026/03/09 14:11:03 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** _trim_newline:
**     Erases \n in given string
*/
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

/*
** _parse_data:
**     Iterate through the map to fill it
*/
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

/*
** parse_fil:
**     Parses file to t_mdata structure
**
**     @param *game  pointer to t_game super-structure
**     @param *arg   file path
**     @return pointer to t_mdata structure
*/
t_mdata	*parse_file(t_game *game, char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error_exit(NULL, game->m, NULL, "[!] Parsing Error: unreadable file\n");
	_parse_data(game->m, fd);
	close(fd);
	return (game->m);
}
