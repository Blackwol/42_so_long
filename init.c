/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 04:13:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data_vars(t_data *data)
{
	data->imgs = ft_calloc(1, sizeof(t_img));
	return ;
}

void	init_map_vars(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;
	map->moves = 0;
	map->collected = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->collectable_total = 0;
	return ;
}
