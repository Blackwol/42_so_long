/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:02:52 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:02:53 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_game_rules_e(t_map *map)
{
	if (map->e_count < 1)
	{
		printf("Error\n");
		printf("Map must have at least one E position.\n");
		return (1);
	}
	return (invalid_game_rules_c(map));
}

int	invalid_game_rules_c(t_map *map)
{
	if (map->collectable_total < 1)
	{
		printf("Error\n");
		printf("Map must have at least one C position.\n");
		return (1);
	}
	return (invalid_game_rules_p(map));
}

int	invalid_game_rules_p(t_map *map)
{
	if (map->p_count < 1)
	{
		printf("Error\n");
		printf("Map must have at least one P position.\n");
		return (1);
	}
	if (map->p_count > 1)
		handle_more_one_p(map);
	return (0);
}
