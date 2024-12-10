/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:17:39 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/10 17:36:44 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_minimap(int i, t_pos startpos, t_core *core)
{
	t_pos	end;
	float	dx;
	float	dy;

	dx = cosf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
	dy = sinf(deg2rad(core->cast.angle[i])) * core->cast.casts[i];
	end.x = startpos.x + dx * DEFUNIT;
	end.y = startpos.y + dy * DEFUNIT;
	mlx_put_line(&core->layer[MINIMAP_LAYER], startpos, end, increase_lighting(Void, 40));
}
