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

int	validate_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (ft_strcmp(extension, ".ber"))
		return (0);
	else
	{
		write(1, "Wrong extension.\n", 17);
		return (1);
	}
}

int	validate_file_exist(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		printf("File doesn't exists.\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	validate_file_presence(int argc)
{
	if (argc < 2)
	{
		write(1, "File nil.\n", 10);
		return (1);
	}
	else
		return (0);
}
