/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/01/27 20:21:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_top_wall(char **game_map, int max_countx)
{
	int	countx;
	int	county;

	countx = 0;
	county = 0;
	while (game_map[countx][county])
	{
		if (game_map[countx][county] != '1' && game_map[countx][county] != '\n')
		{
			write(1, "Map not surrounded by walls.\n", 29);
			return (1);
		}
		county++;
	}
	county--;
	return (invalid_right_wall(game_map, countx, county, max_countx));
}

int	invalid_right_wall(char **game_map, int cx, int cy, int max_cx)
{
	while (cx < max_cx)
	{
		if (game_map[cx][cy] != '1' && game_map[cx][cy] != '\n')
		{
			write(1, "Map not surrounded by walls.\n", 29);
			return (1);
		}
		cx++;
	}
	cx--;
	return (invalid_low_wall(game_map, cx, cy));
}

int	invalid_low_wall(char **game_map, int countx, int county)
{
	while (county >= 0)
	{
		if (game_map[countx][county] != '1' && game_map[countx][county] != '\n')
		{
			write(1, "Map not surrounded by walls.\n", 29);
			return (1);
		}
		county--;
	}
	county++;
	return (invalid_left_wall(game_map, countx, county));
}

int	invalid_left_wall(char **game_map, int countx, int county)
{
	while (countx >= 0)
	{
		if (game_map[countx][county] != '1' && game_map[countx][county] != '\n')
		{
			write(1, "Map not surrounded by walls.\n", 29);
			return (1);
		}
		countx--;
	}
	countx++;
	return (0);
}
