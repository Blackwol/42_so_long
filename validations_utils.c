/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 04:13:12 by coder            ###   ########.fr       */
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
