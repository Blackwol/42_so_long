/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_imgs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 04:42:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_imgs(t_data *data)
{
	generate_wall(data);
	generate_floor(data);
	generate_collectable(data);
	generate_player(data);
	generate_exit(data);
	return ;
}

void	generate_wall(t_data *data)
{
	data->imgs->img_wall = mlx_xpm_file_to_image(data->mlx,
			"./imgs/smaller_wall.xpm",
			&data->imgs->img_width_wall,
			&data->imgs->img_height_wall);
	return ;
}

void	generate_floor(t_data *data)
{
	data->imgs->img_floor = mlx_xpm_file_to_image(data->mlx,
			"./imgs/smaller_floor.xpm",
			&data->imgs->img_width_floor,
			&data->imgs->img_height_floor);
	return ;
}

void	generate_collectable(t_data *data)
{
	data->imgs->img_collectable = mlx_xpm_file_to_image(data->mlx,
			"./imgs/smaller_collectable.xpm",
			&data->imgs->img_width_collectable,
			&data->imgs->img_height_collectable);
	return ;
}
