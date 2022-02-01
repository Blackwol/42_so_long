/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 03:21:29 by coder            ###   ########.fr       */
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

int	get_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_w)
		move_w(data);
	if (keysym == XK_a)
		move_a(data);
	if (keysym == XK_s)
		move_s(data);
	if (keysym == XK_d)
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
			"Yugioh game");
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
