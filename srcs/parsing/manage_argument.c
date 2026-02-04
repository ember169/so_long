/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:09:12 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/04 17:27:19 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	manage_argument(char *arg, t_mdata *map_data)
{
	int		fd;
	char	buf[1025];
	char	*tmp;
	char	*map;
	int		i;

	fd = open(arg, O_RDONLY);
	if (!fd)
		error_exit(NULL, "[!] Error opening file\n");
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, sizeof(buf) - 1);
		if (i == -1)
			error_exit(NULL, "[!] Error reading file\n");
		buf[i] = '\0';
		tmp = map;
		map = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = ft_strjoin(tmp, buf);
	}

	
	map_data->split = ft_split(buf, '\n');
	if (!map_data->split)
		error_exit(NULL, "[!] Error splitting map string\n");

	return (free(map));
	// if (!map_checker(map))
	// 	error_exit(NULL, "[!] Incorrect map\n");
}