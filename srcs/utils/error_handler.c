/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:06:16 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 16:10:15 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_error(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return ;
}

void	error_exit(t_wdata *w, t_mdata *m, t_assets *a, char *errmsg)
{
	print_error(errmsg);
	mlx_loop_end(w->mlx_ptr);
	free_all(w, m, a);
	ft_printf("[i] Everything has been properly freed, exiting cleanly\n");
	exit(1);
}

int	close_button_handler(t_game *g)
{
	def_exit(g->w, g->m, g->a, "[i] Close button pressed\n");
	return (0);
}

void	def_exit(t_wdata *w, t_mdata *m, t_assets *a, char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	mlx_loop_end(w->mlx_ptr);
	free_all(w, m, a);
	ft_printf("[i] Everything has been properly freed, exiting cleanly\n");
	exit(0);
}
