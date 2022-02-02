/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:36:03 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:36:04 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increase_chars_count(t_map *map)
{
	if (map->game_map[map->pos_x][map->pos_y] == 'C')
		map->collectable_total++;
	if (map->game_map[map->pos_x][map->pos_y] == 'P')
		map->p_count++;
	if (map->game_map[map->pos_x][map->pos_y] == 'E')
		map->e_count++;
	return ;
}

static void	print_empty_line_error(char *str)
{
	free(str);
	printf("Error\nEmpty line found.\n");
	return ;
}

int	validate_empty_lines(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '\n')
	{
		print_empty_line_error(str);
		return (1);
	}
	if (str[ft_strlen(str) - 1] == '\n')
	{
		print_empty_line_error(str);
		return (1);
	}
	while (str[index])
	{
		if (str[index] == '\n' && str[index + 1] == '\n')
		{
			print_empty_line_error(str);
			return (1);
		}
		index++;
	}
	return (0);
}

void	handle_more_one_p(t_map *map)
{
	int	x;
	int	y;
	int	current_count_p;

	current_count_p = 0;
	x = 0;
	y = 0;
	while (map->game_map[x])
	{
		while (map->game_map[x][y])
		{
			if (map->game_map[x][y] == 'P' && current_count_p > 0)
				map->game_map[x][y] = '0';
			else if (map->game_map[x][y] == 'P')
				current_count_p++;
			y++;
		}
		y = 0;
		x++;
	}
	return ;
}
