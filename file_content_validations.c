/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2020/01/20 16:32:48 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_chars(t_map map)
{
	map.position_x = 0;
	map.position_y = 0;
	while (map.game_map[map.position_x])
	{
		while (map.game_map[map.position_x][map.position_y])
		{
			if (invalid_char(map.game_map[map.position_x][map.position_y]))
				return (1);
			map.position_y++;
		}
		map.position_y = 0;
		map.position_x++;
	}
	if (shape_invalid(map.game_map))
		return (1);
	if (invalid_game_rules_e(map))
		return (1);
	if (invalid_top_wall(map.game_map, map.position_x))
		return (1);
	return (0);
}

int	shape_invalid(char **game_map)
{
	int	count;
	int	length;
	int	len_row_before;

	len_row_before = 0;
	count = 0;
	length = 0;
	while (game_map[count])
	{
		while (game_map[count][length])
			length++;
		if (count == 0)
			len_row_before = length;
		if (len_row_before != length)
		{
			write(1, "Map is not a rectangle.\n", 24);
			return (1);
		}
		len_row_before = length;
		length = 0;
		count++;
	}
	return (check_rectangular_shape(count, len_row_before));
}

int	check_rectangular_shape(int height, int row)
{
	if (height == row)
	{
		write(1, "Map is not a rectangle.\n", 24);
		return (1);
	}
	return (0);
}

int	invalid_char(char element)
{
	if ((element != 'P' && element != 'p') \
		&& (element != 'E' && element != 'e') \
		&& (element != 'C' && element != 'c') \
		&& element != '1' && element != '0' && element != '\n')
	{
		write(1, "Invalid character found!\n", 25);
		return (1);
	}
	return (0);
}
