/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_imgs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:30:28 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:30:29 by pcardoso         ###   ########.fr       */
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
