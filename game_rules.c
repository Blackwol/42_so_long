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

int	invalid_game_rules_e(t_map map)
{
	int	count_e;

	count_e = 0;
	map.position_x = 0;
	map.position_y = 0;
	while (map.game_map[map.position_x])
	{
		while (map.game_map[map.position_x][map.position_y])
		{
			if (map.game_map[map.position_x][map.position_y] == 'E')
				count_e++;
			if (map.game_map[map.position_x][map.position_y] == 'e')
				count_e++;
			map.position_y++;
		}
		map.position_y = 0;
		map.position_x++;
	}
	if (count_e < 1)
	{
		write(1, "Must have at least one E position.\n", 35);
		return (1);
	}
	return (invalid_game_rules_c(map));
}

int	invalid_game_rules_c(t_map map)
{
	int	count_c;

	count_c = 0;
	map.position_x = 0;
	map.position_y = 0;
	while (map.game_map[map.position_x])
	{
		while (map.game_map[map.position_x][map.position_y])
		{
			if (map.game_map[map.position_x][map.position_y] == 'C')
				count_c++;
			if (map.game_map[map.position_x][map.position_y] == 'c')
				count_c++;
			map.position_y++;
		}
		map.position_y = 0;
		map.position_x++;
	}
	if (count_c < 1)
	{
		write(1, "Must have at least one C position.\n", 35);
		return (1);
	}
	return (invalid_game_rules_p(map));
}

int	invalid_game_rules_p(t_map map)
{
	int	count_p;

	count_p = 0;
	map.position_x = 0;
	map.position_y = 0;
	while (map.game_map[map.position_x])
	{
		while (map.game_map[map.position_x][map.position_y])
		{
			if (map.game_map[map.position_x][map.position_y] == 'P')
				count_p++;
			if (map.game_map[map.position_x][map.position_y] == 'p')
				count_p++;
			map.position_y++;
		}
		map.position_y = 0;
		map.position_x++;
	}
	if (count_p < 1)
	{
		write(1, "Must have at least one P position.\n", 35);
		return (1);
	}
	return (0);
}
