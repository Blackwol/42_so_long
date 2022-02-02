/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_validations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:01:58 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:01:59 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_chars(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;
	while (map->game_map[map->pos_x])
	{
		while (map->game_map[map->pos_x][map->pos_y])
		{
			if (invalid_char(map->game_map[map->pos_x][map->pos_y]))
				return (1);
			increase_chars_count(map);
			map->pos_y++;
		}
		map->width = map->pos_y;
		map->pos_y = 0;
		map->pos_x++;
	}
	map->height = map->pos_x;
	if (shape_invalid(map->game_map))
		return (1);
	if (invalid_top_wall(map->game_map, map->pos_x))
		return (1);
	if (invalid_game_rules_e(map))
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
			printf("Error\nMap is not a rectangle.\n");
			return (1);
		}
		len_row_before = length;
		length = 0;
		count++;
	}
	return (0);
}

int	invalid_char(char element)
{
	if ((element != 'P') \
		&& (element != 'E') \
		&& (element != 'C') \
		&& element != '1' && element != '0' && element != '\n')
	{
		printf("Error\nInvalid character found!\n");
		return (1);
	}
	return (0);
}

int	validate_numbers_of_chars(char *str)
{
	if (ft_strlen(str) < 15)
	{
		free(str);
		printf("Error\nMap must have at least 15 characters.\n");
		return (1);
	}
	return (0);
}
