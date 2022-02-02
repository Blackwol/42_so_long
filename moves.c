/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:31:29 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:31:30 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if (data->map->game_map[pos_x - 1][pos_y] == '0')
	{
		data->map->game_map[pos_x - 1][pos_y] = 'P';
		data->map->p_pos_x = pos_x - 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x - 1][pos_y] == 'C')
	{
		data->map->collected++;
		data->map->game_map[pos_x - 1][pos_y] = 'P';
		data->map->p_pos_x = pos_x - 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x - 1][pos_y] == 'E')
		check_can_exit(data);
	render_map(data);
}

void	move_a(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if (data->map->game_map[pos_x][pos_y - 1] == '0')
	{
		data->map->game_map[pos_x][pos_y - 1] = 'P';
		data->map->p_pos_y = pos_y - 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x][pos_y - 1] == 'C')
	{
		data->map->collected++;
		data->map->game_map[pos_x][pos_y - 1] = 'P';
		data->map->p_pos_y = pos_y - 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x][pos_y - 1] == 'E')
		check_can_exit(data);
	render_map(data);
}

void	move_s(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if (data->map->game_map[pos_x + 1][pos_y] == '0')
	{
		data->map->game_map[pos_x + 1][pos_y] = 'P';
		data->map->p_pos_x = pos_x + 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x + 1][pos_y] == 'C')
	{
		data->map->collected++;
		data->map->game_map[pos_x + 1][pos_y] = 'P';
		data->map->p_pos_x = pos_x + 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x + 1][pos_y] == 'E')
		check_can_exit(data);
	render_map(data);
}

void	move_d(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if (data->map->game_map[pos_x][pos_y + 1] == '0')
	{
		data->map->game_map[pos_x][pos_y + 1] = 'P';
		data->map->p_pos_y = pos_y + 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x][pos_y + 1] == 'C')
	{
		data->map->collected++;
		data->map->game_map[pos_x][pos_y + 1] = 'P';
		data->map->p_pos_y = pos_y + 1;
		data->map->game_map[pos_x][pos_y] = '0';
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
	}
	if (data->map->game_map[pos_x][pos_y + 1] == 'E')
		check_can_exit(data);
	render_map(data);
}

void	check_can_exit(t_data *data)
{
	if (data->map->collected == data->map->collectable_total)
	{
		data->map->moves++;
		printf("Moves: %i\n", data->map->moves);
		printf("Congratz!! U won the game with %i moves! =D\n",
			data->map->moves);
		close_window(data);
	}
	return ;
}
