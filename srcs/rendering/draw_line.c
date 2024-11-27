/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:23:25 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 17:55:48 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_line(t_layer *layer, t_pos a, t_pos b, t_color_type color)
{
	float	deltaX = b.x - a.x;
	float	deltaY = b.y - a.y;

	int		pixels = (int)sqrtf((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	float	pixelX = a.x;
	float	pixelY = a.y;
	while (pixels)
	{
		draw_pixel(pixelX, pixelY, color, layer);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}
