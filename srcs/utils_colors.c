/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 17:47:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_type	increase_lighting(t_color_type col, int by)
{
	t_color_type	ret;

	ret = col;
	ret = (by << 24) | (ret & 0x00ffffff);
	return (ret);
}

	// char[3] to color
t_color	ctocol(t_uchar r, t_uchar g, t_uchar b)
{
	t_color	ret;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret._overflow = FALSE;
	return (ret);
}

t_color	stocol(const char *str)
{
	size_t	i;
	char	**split;
	int		tmp;
	t_color	ret;

	ret._overflow = FALSE;
	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		tmp = ft_atoi(split[i]);
		if (tmp > 255)
			ret._overflow = TRUE;
		i++;
	}

	ft_dfree((void **)split);
	ret.bytes_wrote = i;
	ret.b = tmp;
	return (ret);
}

//F 123, 456, 789
//C 987, 654, 321
