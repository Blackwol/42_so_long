/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 03:47:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd, char *str_aux)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (!(buffer))
			break ;
		str_aux = ft_strjoin(str_aux, buffer);
		free(buffer);
	}
	free(buffer);
	return (str_aux);
}

char	**create_board(char *filename)
{
	char	**game_map;
	int		fd;
	char	*str_aux;

	str_aux = ft_strdup("");
	if (!str_aux)
		return (NULL);
	fd = open(filename, O_RDONLY);
	str_aux = read_file(fd, str_aux);
	close(fd);
	if (validate_numbers_of_chars(str_aux))
		exit (0);
	game_map = ft_split(str_aux, '\n');
	return (game_map);
}

void	free_map(t_map *map)
{
	int	index;

	index = 0;
	while (map->game_map[index])
	{
		free(map->game_map[index]);
		index++;
	}
	free(map->game_map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (validate_file_presence(argc))
		return (0);
	if (validate_extension(argv[1]))
		return (0);
	if (validate_file_exist(argv[1]))
		return (0);
	map.game_map = create_board(argv[1]);
	init_map_vars(&map);
	if (validate_chars(&map))
	{
		free_map(&map);
		return (0);
	}
	start_game(map);
	free_map(&map);
	return (0);
}
