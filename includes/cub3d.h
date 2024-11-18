/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:48 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/18 23:36:56 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "MLX42-2.4.1/include/MLX42/MLX42.h"
# include "libft.h"
# include "platform.h"
# include "defs.h"

	//* main files (cub3d.c)
void	cub3d(t_core *core);
void	game(t_core *core);

	//* init.c
void	init_core(t_core *core);
void	init_mlx_env(t_core *core);
void	setup_mlx_hooks(t_core *core);

	//* terminate.c
void	exit_strerror(char	*error_desc, t_core *core);
void	exit_cub3d(int errcode, t_core *core);
void	free_core(t_core *core);
void	free_core_map(t_core *core);

	//* key_handing
void	handle_pressing_alt_key(mlx_key_data_t keyd, t_core *core);
void	handle_releasing_alt_key(mlx_key_data_t keyd, t_core *core);
void	handle_esc_key(mlx_key_data_t keyd, t_core *core);
void	handle_player_key(mlx_key_data_t keyd, t_core *core);
void	handle_crouchplayer_key(mlx_key_data_t keyd, t_core *core);

	//* utils
t_color	ctocol(t_uchar r, t_uchar g, t_uchar b);
t_uint	coltohexa(t_color col);
t_color	stocol(const char *str);

	//* hooks.c
void	cub3d_close_hook(t_core *core);
void	cub3d_key_hook(mlx_key_data_t keyd, t_core *core);
void	cub3d_cursor_hook(double xpos, double ypos, t_core *core);
void	cub3d_scroll_hook(double xdelta, double ydelta, t_core *core);
void	cub3d_resize_hook(int width, int height, t_core *core);
void	cub3d_mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, t_core *core);

	//* parsing/parsing.c
void	parse_map(t_core *core);

#endif