/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:31:20 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:31:21 by pcardoso         ###   ########.fr       */
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
