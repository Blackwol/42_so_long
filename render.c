/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 06:06:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_in_window(t_data *data, int img_x, int img_y)
{
	if (data->map->game_map[data->map->pos_x][data->map->pos_y] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->img_wall, img_x, img_y);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->img_floor, img_x, img_y);
	if (data->map->game_map[data->map->pos_x][data->map->pos_y] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->img_collectable, img_x + 16, img_y + 10);
	if (data->map->game_map[data->map->pos_x][data->map->pos_y] == 'P')
	{
		data->map->p_pos_x = data->map->pos_x;
		data->map->p_pos_y = data->map->pos_y;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->img_player, img_x + 16, img_y + 10);
	}
	if (data->map->game_map[data->map->pos_x][data->map->pos_y] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->img_exit, img_x + 11, img_y + 9);
	return ;
}

int	render_map(t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = 0;
	img_y = 0;
	data->map->pos_x = 0;
	data->map->pos_y = 0;
	while (data->map->game_map[data->map->pos_x])
	{
		while (data->map->game_map[data->map->pos_x][data->map->pos_y])
		{
			put_img_in_window(data, img_x, img_y);
			data->map->pos_y++;
			img_x = img_x + 64;
		}
		img_x = 0;
		img_y = img_y + 64;
		data->map->pos_y = 0;
		data->map->pos_x++;
	}
	return (0);
}
