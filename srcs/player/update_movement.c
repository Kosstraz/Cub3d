/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:23:15 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/15 15:59:47 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_movement(t_player *player)
{
	update_head_points(player);
	update_legl_points(player);
	update_legr_points(player);
	update_corps_points(player);
	update_arml_points(player);
	update_armr_points(player);
//	printf("pos j x: %f y: %f\n", player->position.x, player->position.y);
//	printf("pos corps x: %f y: %f\n", player->entity.liste[0]->x, player->entity.liste[0]->y);
}
