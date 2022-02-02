/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 06:02:40 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 06:02:42 by pcardoso         ###   ########.fr       */
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
		printf("Error\nWrong extension.\n");
		return (1);
	}
}

int	validate_file_exist(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		printf("Error\nFile doesn't exist.\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	validate_file_presence(int argc)
{
	if (argc < 2)
	{
		printf("Error\nFile nil.\n");
		return (1);
	}
	else if (argc > 2)
	{
		printf("Error\nOnly one parameter allowed.\n");
		return (1);
	}
	else
		return (0);
}
