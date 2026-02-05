/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:09:12 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/05 14:29:14 by lgervet          ###   ########.fr       */
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
	return ;
}

static int	_count_columns(t_mdata *map_data)
{
	int	row_nb;
	int	col_nb;
	int	tmp;

	tmp = 0;
	row_nb = 0;
	col_nb = 0;
	while (map_data->map[row_nb])
	{
		col_nb = 0;
		while (map_data->map[row_nb][col_nb])
			col_nb++;
		if (map_data->map[row_nb][col_nb - 1] == '\n')
		{
			map_data->map[row_nb][col_nb - 1] = '\0';
			col_nb--;
		}
		if (tmp != 0 && col_nb != tmp)
			error_exit(NULL, map_data, "[!] Uneven columns number\n");
		tmp = col_nb;
		row_nb++;
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
	if (map_data->row_nb == map_data->col_nb)
		error_exit(NULL, map_data, "[!] Map is square instead of rectangular\n");
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
