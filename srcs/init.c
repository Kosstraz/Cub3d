/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:37:07 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/03 17:48:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	init_player(t_player *player)
{
	ft_memset(player, 0, sizeof(t_player));
	player->life = MAX_LIFE;
}

inline static void	init_core_map(t_core *core)
{
	core->map.generated = FALSE;
	core->map.bufmax = DEFMAPBUF;
	core->map.buf = (char **)malloc(sizeof(char *) * DEFMAPBUF);
	core->map.buflens = NULL;
	core->map.buflens_size = 0;
	core->map.filepath.north = NULL;
	core->map.filepath.south = NULL;
	core->map.filepath.east = NULL;
	core->map.filepath.west = NULL;
	core->map.cf_colors[C] = ctocol(0, 0, 0);
	core->map.cf_colors[F] = ctocol(0, 0, 0);
	core->map.cf_colors[C]._overflow = FALSE;
	core->map.cf_colors[F]._overflow = FALSE;
}

inline void	init_core(t_core *core)
{
	int	i;

	i = 0;
	core->mouse_visible = FALSE;
	core->half_height = DEFHEIGHT / 2.f;
	core->half_width = DEFWIDTH / 2.f;
	core->imgs.fps = NULL;
	core->imgs.minimap = NULL;
	core->minimap.position.x = 0;
	core->minimap.position.y = 0;
	core->minimap.size.x = 0;
	core->minimap.size.y = 0;
	core->input_action.key_w = FALSE;
	core->input_action.key_a = FALSE;
	core->input_action.key_s = FALSE;
	core->input_action.key_d = FALSE;
	core->input_action.key_right = FALSE;
	core->input_action.key_left = FALSE;
	core->layer[MINIMAP_LAYER].pixels = NULL;
	core->layer[CAST_LAYER].pixels = NULL;
	core->fps_cooldown = 0;
	init_player(&core->player[LOCAL]);
	init_player(&core->player[DISTANT]);
	init_core_map(core);
	init_cast(&core->cast, core->player[LOCAL]);
}

inline void	init_mlx_env(t_core *core)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	if (core->network.is_host)
		core->mlx = mlx_init(DEFWIDTH, DEFHEIGHT, GAME_TITLE_S, true);
	else
		core->mlx = mlx_init(DEFWIDTH, DEFHEIGHT, GAME_TITLE, true);
	if (!core->mlx->window)
		exit_cub3d(1, core);
	else if (!core->mlx)
		exit(1);
	mlx_set_cursor_mode(core->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(core->mlx, core->half_width, core->half_height);
	core->minimap.size.x = core->map.buflens_max * DEFUNIT;
	core->minimap.size.y = core->map.bufmax * DEFUNIT;
	core->minimap.position.x = core->mlx->width - core->map.buflens_max * DEFUNIT - 10;
	core->minimap.position.y = 10;
	core->imgs.minimap = mlx_new_image(core->mlx,
		core->minimap.size.x,
		core->minimap.size.y);
	core->imgs.cast = mlx_new_image(core->mlx, core->mlx->width, core->mlx->height);
	mlx_image_to_window(core->mlx, core->imgs.minimap, core->minimap.position.x, core->minimap.position.y);
	mlx_image_to_window(core->mlx, core->imgs.cast, 0, 0);
	init_layer(core->imgs.minimap, &core->layer[MINIMAP_LAYER]);
	init_layer(core->imgs.cast, &core->layer[CAST_LAYER]);
	//printf("%i %i init\n", core->mlx->width, core->mlx->height);
}

inline void	setup_mlx_hooks(t_core *core)
{
	mlx_mouse_hook(core->mlx, (mlx_mousefunc)cub3d_mouse_hook, core);
	mlx_key_hook(core->mlx, (mlx_keyfunc)cub3d_key_hook, core);
	mlx_close_hook(core->mlx, (mlx_closefunc)cub3d_close_hook, core);
	mlx_cursor_hook(core->mlx, (mlx_cursorfunc)cub3d_cursor_hook, core);
	mlx_scroll_hook(core->mlx, (mlx_scrollfunc)cub3d_scroll_hook, core);
	mlx_resize_hook(core->mlx, (mlx_resizefunc)cub3d_resize_hook, core);
	mlx_loop_hook(core->mlx, (t_mlx_loopfunc)game, core);
}
