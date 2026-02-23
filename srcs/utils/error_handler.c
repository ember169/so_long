/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:06:16 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/23 14:30:49 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
** error_exit:
**     Function to exit cleanly when there is an error
**
**     @param *w       pointer to t_wdata.
**     @param *m       pointer to t_mdata.
**     @param *a       pointer to t_assets.
**     @param *errmsg  message to display before exiting.
*/
void	error_exit(t_wdata *w, t_mdata *m, t_assets *a, char *errmsg)
{
	write(2, "Error\n", 6);
	if (errmsg)
		write(2, errmsg, ft_strlen(errmsg));
	free_all(w, m, a);
	ft_printf("[i] Everything has been properly freed, exiting cleanly\n");
	exit(1);
}

/*
** def_exit:
**     Function to exit cleanly when there is no error
**
**     @param *w    pointer to t_wdata.
**     @param *m    pointer to t_mdata.
**     @param *a    pointer to t_assets.
**     @param *msg  message to display before exiting.
*/
void	def_exit(t_wdata *w, t_mdata *m, t_assets *a, char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	mlx_loop_end(w->mlx_ptr);
	free_all(w, m, a);
	ft_printf("[i] Everything has been properly freed, exiting cleanly\n");
	exit(0);
}

/*
** close_button_handler:
**     Handles event for exiting game with the window cross button
**
**     @param *g  pointer to super-structure t_game.
*/
int	close_button_handler(t_game *g)
{
	def_exit(g->w, g->m, g->a, "[i] Close button pressed\n");
	return (0);
}
