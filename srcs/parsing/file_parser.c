/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:09:12 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/06 18:51:10 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_initialize_mdata(t_mdata *map_data)
{
	map_data->col_nb = 0;
	map_data->row_nb = 0;
	map_data->map = malloc(1025);
	if (!map_data->map)
		error_exit(NULL, map_data, "[!] Error initalizing map_data->map\n");
	map_data->d_map = malloc(1025);
	if (!map_data->map)
		error_exit(NULL, map_data, "[!] Error initalizing map_data->d_map\n");
	return ;
}

static int	_count_columns(t_mdata *map_data)
{
	int	y;
	int	x;
	int	tmp;

	tmp = 0;
	y = 0;
	x = 0;
	while (map_data->map[y])
	{
		x = 0;
		while (map_data->map[y][x])
			x++;
		if (map_data->map[y][x - 1] == '\n')
		{
			map_data->map[y][x - 1] = '\0';
			x--;
		}
		if (tmp != 0 && x != tmp)
			error_exit(NULL, map_data, "[!] Uneven columns number\n");
		tmp = x;
		y++;
	}
	return (tmp);
}

static void	_parse_data(t_mdata *map_data, int fd)
{
	int	i;

	i = 0;
	map_data->map[i] = get_next_line(fd);
	while (map_data->map[i])
	{
		if (i == 1025)
			error_exit(NULL, map_data, "[!] Map size > 1025 rows\n");
		map_data->map[++i] = get_next_line(fd);
	}
	map_data->row_nb = i;
	map_data->col_nb = _count_columns(map_data);
}

t_mdata	*parse_file(char *arg)
{
	t_mdata	*map_data;
	int		fd;

	map_data = (t_mdata *)malloc(sizeof(t_mdata));
	if (!map_data)
		error_exit(NULL, NULL, "[!] Error initalizing t_mdata\n");
	_initialize_mdata(map_data);
	fd = open(arg, O_RDONLY);
	if (!fd)
		error_exit(NULL, map_data, "[!] Error opening file\n");
	_parse_data(map_data, fd);
	close(fd);
	return (map_data);
}
