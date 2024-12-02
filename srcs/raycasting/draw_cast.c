	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:52:09 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/27 15:49:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_core *core)
{
	uint32_t	i;
	uint32_t	j;
	long		start;

	start = get_time2();
	i = 0;
	while (i < core->imgs.cast->height)
	{
		j = 0;
		while (j < core->imgs.cast->width)
		{
			draw_pixel(j, i, 0x00111111, &core->layer[CAST_LAYER]);
			j++;
		}
		i++;
	}
	// printf("clear %i %i time elapsed : %ld\n", core->mlx->height, core->mlx->width, get_time() - start);
}

void	draw_col(int x, float length, t_core *core)
{
	int		i;
	float	y;
	float	nb_pixels;
	long	col;
	long	dark;

	nb_pixels = 1000 / (length / 2);
	if (length > 130)
		col = 0xff000000;
	else
		col = 0xff000000 - 0x00010101 * (long)(length / 130 * 256);
	i = 0;
	while (i < (int)nb_pixels)
	{
		y = (float) core->imgs.cast->height / 2.f + ((float) i - nb_pixels / 2.f);
		draw_pixel(x, (int)y, col, &core->layer[CAST_LAYER]);
		++i;
	}
}

void	draw_cast(t_core *core)
{
	uint32_t	i;

	i = 0;
	while (i < core->imgs.cast->width)
	{
		draw_col(i, core->cast.casts[i], core);
		i++;
	}
}
