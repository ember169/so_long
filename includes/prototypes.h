/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:24:26 by lgervet           #+#    #+#             */
/*   Updated: 2026/02/12 11:15:33 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

t_mdata		*parse_file(t_game *game, char *arg);
t_mdata		*init_mdata(char *file_path);
t_wdata		*init_wdata(t_mdata *m, int *mlx, char *title);
t_assets	*init_assets(t_wdata *w, t_mdata *m);
void		free_all(t_wdata *window, t_mdata *mdata, t_assets *assets);
void		error_exit(t_wdata *w, t_mdata *m, t_assets *a, char *errmsg);
void		def_exit(t_wdata *w, t_mdata *m, t_assets *a, char *msg);
int			valid_map(t_mdata *mdata);
int			valid_path(t_mdata *mdata);
void		render_map(t_game *g);
void		render_player(t_game *g, int x, int y);
void		main_mlx_loop(t_game *g);
void		move_char(int key, t_game *g);
void		update_counter(t_game *g);
int			count_file_lines(char *file_path);

#endif