/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:53 by mkhoury           #+#    #+#             */
/*   Updated: 2024/11/25 16:13:49 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg2rad(double deg)
{
	return (deg / 360 * PI);
}
