/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:44 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/22 17:33:09 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_key_hook(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.action == MLX_PRESS)
	{
		handle_esc_key(keyd, core);
		handle_pressing_alt_key(keyd, core);
		handle_player_key(keyd, core);
	}
	else if (keyd.action == MLX_RELEASE)
	{
		handle_releasing_alt_key(keyd, core);
		handle_crouchplayer_key(keyd, core);
	}
	else if (keyd.action == MLX_REPEAT)
	{
	}
}

void	cub3d_mouse_hook(mouse_key_t button,
						action_t action,
						modifier_key_t mods,
						t_core *core)
{
	(void)button;
	(void)action;
	(void)mods;
	(void)core;
}

void	cub3d_close_hook(t_core *core)
{
	exit_cub3d(0, core);
}

void	cub3d_cursor_hook(double xpos, double ypos, t_core *core)
{
	(void)xpos;
	(void)ypos;
	(void)core;
}

void	cub3d_scroll_hook(double xdelta, double ydelta, t_core *core)
{
	(void)xdelta;
	(void)ydelta;
	(void)core;
}
