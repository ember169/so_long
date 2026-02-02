/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:17:03 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/02 13:02:13 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_error(char *msg)
{
	if (!msg)
		msg = "[!] Error\n";
	write(2, &msg, ft_strlen(msg));
	return ;
}

void	error_exit(t_wdata *window, char *errmsg)
{
	print_error(errmsg);
	if (window->w_ptr)
	{
		mlx_clear_window(window->mlx_ptr, window->w_ptr);
		mlx_destroy_window(window->mlx_ptr, window->w_ptr);
	}
	free(window);
	exit(1);
}