/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 19:13:06 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	put_images_to_window(t_core *core)
{
	mlx_image_to_window(core->mlx, core->imgs.fps, 0, 0);
	core->minimap.position.x = core->mlx->width - core->map.buflens_max * DEFUNIT - 10;
	core->minimap.position.y = 10;
	mlx_image_to_window(
		core->mlx,
		core->imgs.minimap,
		core->minimap.position.x,
		core->minimap.position.y);
}

void	game(t_core *core)
{
	//if (core->multi.is_active)
	//		... poll events
	if (!core->mouse_visible)
		mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	// draw ray casting
	// draw entity
	draw_minimap(core);
	show_fps(core);
	put_images_to_window(core);
}

void	cub3d(t_core *core)
{
	if (!core->multi.is_active || core->multi.is_host)
	{
		if (ft_strncmp_rev(core->map.file, ".cub", 3)
			|| (!ft_strncmp_rev(core->map.file, ".cub", 3)
				&& ft_strlen(core->map.file) == 4))
			exit_strerror(BAD_EXTENSION_FILE_T, core);
		else if (!core->map.generated)
			parse_map(core);
		if (core->multi.is_host)
			send_map(core);
	}
	else if (core->multi.is_active)
		recv_map(core);
	print_map(*core);
	init_mlx_env(core);
	setup_mlx_hooks(core);
	mlx_loop(core->mlx);
	free_core(core);
	//close_connection(core); // ? temporaire pour des tests
}
