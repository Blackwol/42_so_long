/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_imgs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 04:44:56 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_exit(t_data *data)
{
	data->imgs->img_exit = mlx_xpm_file_to_image(data->mlx,
			"./imgs/smaller_exit.xpm",
			&data->imgs->img_width_exit,
			&data->imgs->img_height_exit);
	return ;
}

void	generate_player(t_data *data)
{
	data->imgs->img_player = mlx_xpm_file_to_image(data->mlx,
			"./imgs/smaller_player.xpm",
			&data->imgs->img_width_player,
			&data->imgs->img_height_player);
	return ;
}
