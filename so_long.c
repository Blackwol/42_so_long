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

char	*read_file(int fd, char *str_aux)
{
	int		read_ret;
	char	*buffer;

	read_ret = 1;
	buffer = ft_calloc(42, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_ret)
	{
		read_ret = read(fd, buffer, 42);
		if (read_ret == 0)
			break ;
		str_aux = ft_strjoin(str_aux, buffer);
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
	game_map = ft_split(str_aux, '\n');
	return (game_map);
}

void	free_map(t_map map)
{
	int	index;

	index = 0;
	while (map.game_map[index])
	{
		free(map.game_map[index]);
		index++;
	}
	free(map.game_map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		index;

	index = 0;
	if (validate_file_presence(argc))
		return (1);
	if (validate_extension(argv[1]))
		return (1);
	if (validate_file_exist(argv[1]))
		return (1);
	map.game_map = create_board(argv[1]);
	if (validate_chars(map))
	{
		free_map(map);
		return (1);
	}
	while (map.game_map[index])
	{
		printf("%s\n", map.game_map[index]);
		index++;
	}
	free_map(map);
	return (1);
}
