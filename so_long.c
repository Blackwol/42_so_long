/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2020/01/20 16:32:48 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_board(char *filename)
{
	char	**game_map;
	int		fd;
	int		read_ret;
	char	buffer[600];

	fd = open(filename, O_RDONLY);
	read_ret = read(fd, buffer, 600);
	close(fd);
	printf("%i\n", read_ret);
	game_map = (char **)ft_calloc(count_endline(buffer), sizeof(char *));
	game_map = ft_split(buffer, '\n');
	return (game_map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (validate_file_presence(argc))
		return (1);
	if (validate_extension(argv[1]))
		return (1);
	map.game_map = create_board(argv[1]);
	if (validate_chars(map))
		return (1);
	while (*map.game_map)
	{
		printf("%s\n", *map.game_map);
		map.game_map++;
	}
	return (1);
}
