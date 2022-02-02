/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:30:06 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:30:07 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs->img_wall);
	mlx_destroy_image(data->mlx, data->imgs->img_floor);
	mlx_destroy_image(data->mlx, data->imgs->img_collectable);
	mlx_destroy_image(data->mlx, data->imgs->img_player);
	mlx_destroy_image(data->mlx, data->imgs->img_exit);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->imgs);
	return ;
}

int	close_window(t_data *data)
{
	free_map(data->map);
	finish_game(data);
	exit (0);
}

int	get_key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	if (keycode == W_KEY)
		move_w(data);
	if (keycode == A_KEY)
		move_a(data);
	if (keycode == S_KEY)
		move_s(data);
	if (keycode == D_KEY)
		move_d(data);
	return (0);
}

int	start_game(t_map map)
{
	t_data	data;

	data.map = &map;
	init_data_vars(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		free(data.imgs);
		return (1);
	}
	data.mlx_win = mlx_new_window(data.mlx,
			map.width * 64,
			map.height * 64,
			"./so_long");
	if (data.mlx_win == NULL)
	{
		free(data.mlx);
		free(data.imgs);
		return (1);
	}
	generate_imgs(&data);
	render_map(&data);
	set_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
