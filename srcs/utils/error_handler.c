/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:06:16 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/10 12:07:15 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(char *msg)
{
	if (!msg)
		msg = "[!] Error\n";
	write(2, msg, ft_strlen(msg));
	return ;
}

void	error_exit(t_wdata *window, t_mdata *mdata, t_assets *assets, char *errmsg)
{
	print_error(errmsg);
	free_all(window, mdata, assets);
	ft_printf("[i] Everything has been properly freed, exiting cleanly\n");
	exit(1);
}