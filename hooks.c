/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:31:12 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:31:13 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 1L << 2, &close_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &get_key_press, data);
	mlx_hook(data->mlx_win, 9, 1L << 21, &render_map, data);
	mlx_loop_hook(data->mlx, &render_map, data);
}
