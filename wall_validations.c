/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:36:11 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:36:12 by pcardoso         ###   ########.fr       */
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
			printf("Error\nMap not surrounded by walls.\n");
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
			printf("Error\nMap not surrounded by walls.\n");
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
			printf("Error\nMap not surrounded by walls.\n");
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
			printf("Error\nMap not surrounded by walls.\n");
			return (1);
		}
		countx--;
	}
	countx++;
	return (0);
}
