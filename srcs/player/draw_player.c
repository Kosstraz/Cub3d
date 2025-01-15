/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:32:22 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/15 16:22:14 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	set_angles(t_component *component, t_pos local)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		component->angle[i] = get_angle(component->points[i].x\
// 		 - local.x, component->points[i].y - local.y);
// 		i++;
// 	}
// }

int	set_distance(t_component *component, t_pos local)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < 8)
	{
		component->distance[i] = sqrtf((component->points[i].x - local.x) * (component->points[i].x  - local.x)\
		+ (component->points[i].y - local.y) * (component->points[i].y - local.y));
		if (component->distance[i] < component->distance[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

bool	check_visible(t_player *distant, t_player *local)
{
	float	angle;
	float	delta;
	float	distance;

	angle = get_angle(distant->position.x - local->position.x, distant->position.y - local->position.y);
	if (angle - local->view.angle > 180.f)
		delta = 360.f - (angle - local->view.angle);
	else if (angle - local->view.angle < -180.f)
		delta = -360.f - (angle - local->view.angle);
	else
		delta = angle - local->view.angle;
	distance = sqrtf((distant->position.x - local->position.x) * (distant->position.x - local->position.x)\
	+ (distant->position.y - local->position.y) * (distant->position.y - local->position.y));
	//if (ft_absf(delta) > 70.f || distance <= 1.f)
	//	return (false);
	return (true);
}

void    draw_player_2(t_core *core, t_player *distant, t_player *local)
{
	int	i;
	int	distances[6][3];

	cpy_ptbl(core, *distant);
	// core->liste[0].points[2].x = 1.f;
	// printf("test :%f\n", core->liste[0].face[0].p1->x);
	if (check_visible(distant, local) == false)
		return ;
	i = 0;
	while (i < 6)
	{
		distances[i][0] = i;
		distances[i][1] = set_distance(&core->liste[i], local->position);
		distances[i][2] = core->liste[i].distance[distances[i][1]];
		i++;
	}
	//sort_distance(&distances);
	i = 0;
	while (i < 1)
	{
		draw_component(core->liste[distances[i][0]], distances[i][1], core);
		i++;
	}
}
