/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/01/30 05:29:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, DestroyNotify, NoEventMask, &close_window, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &get_key_press, data);
	mlx_hook(data->mlx_win, 9, 1L << 21, &render_map, data);
	mlx_loop_hook(data->mlx, &render_map, data);
}
