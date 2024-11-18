/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/18 22:53:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

	//*	default values
# define DEFWIDTH	800
# define DEFHEIGHT	600

	//* constants specifics to cub3d
# define GAME_TITLE		"Alien Isolation"
# define MAX_LIFE		100
# define CROUCH_OFFSET	//inserer int

	//* generic constants
# define TRUE	1
# define FALSE	0
# define BOOL	char

	//* error constants
# define CONCEDE_MAP	"Please concede map .cub in program argument\n"

# define PARSING_ERROR_T	"Error\n"

# define IMPOSSIBLE_TO_OPEN	"Impossible to open file\n"

# define NORTH_TEXTURE_FILE_INVALID_T	"North texture file is invalid\n"
# define SOUTH_TEXTURE_FILE_INVALID_T	"South texture file is invalid\n"
# define EAST_TEXTURE_FILE_INVALID_T	"East texture file is invalid\n"
# define WEST_TEXTURE_FILE_INVALID_T	"West texture file is invalid\n"

# define CEILING_COLOR_FORMAT_INCORRECT_T	"Ceiling color format is incorrect\n"
# define FLOOR_COLOR_FORMAT_INCORRECT_T		"Floor color format is incorrect\n"

# define MAP_NO_PLAYER_SPAWN_T		"There is no player spawn\n"
# define MAP_PLAYER_BLOCKED_T		"The player is blocked at the spawn\n"
# define MAP_PLACE_WITH_NO_WALL_T	"A place with no wall exist\n"

# define FILE_BAD_EXTENSION_T "Please let a \"*.cub\" file\n"
# define FILE_CONFIGURATION_T "Maybe review order of the .cub configuration\n"

#endif