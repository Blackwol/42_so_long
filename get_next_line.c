/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:04:55 by pcardoso          #+#    #+#             */
/*   Updated: 2022/01/30 21:35:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_return_null(char **next_line)
{
	free(*next_line);
	return (NULL);
}

static int	has_newline(char **next_line, char *buffer)
{
	char	*new;

	new = buffer;
	while (*new)
	{
		if (*new == '\n')
			break ;
		new++;
	}
	if (*new != '\n')
		new = NULL;
	if (new == NULL)
		return (0);
	*next_line = strjoin_newline(*next_line, buffer);
	gnl_memmove(buffer, new, gnl_strlen(new));
	buffer[gnl_strlen(new)] = '\0';
	return (1);
}

static void	read_nextline(int fd, char **next_line, char *buffer)
{
	int		read_ret;
	int		has_line;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	while (read_ret > 0)
	{
		buffer[read_ret] = '\0';
		has_line = has_newline(next_line, buffer);
		if (has_line)
			break ;
		else
		{
			*next_line = gnl_strjoin(*next_line, buffer);
			if (!(*next_line))
				break ;
		}
		read_ret = read(fd, buffer, BUFFER_SIZE);
	}
}

static int	fix_check_buffer(char **next_line, char *buffer)
{
	int		i;
	char	*tmp;

	tmp = buffer;
	tmp++;
	i = gnl_strlen(tmp);
	gnl_memmove(buffer, tmp, i);
	buffer[i] = '\0';
	i = has_newline(next_line, buffer);
	if (i <= 0)
	{
		*next_line = gnl_strjoin(*next_line, buffer);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	int			newline_flag;
	char		*next_line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	next_line = gnl_strdup("");
	if (fd < 0 || fd > FOPEN_MAX)
		return (free_return_null(&next_line));
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1 || !next_line)
		return (free_return_null(&next_line));
	newline_flag = 0;
	if (buffer[fd][0] == '\n')
		newline_flag = fix_check_buffer(&next_line, buffer[fd]);
	if (!newline_flag)
		read_nextline(fd, &next_line, buffer[fd]);
	if (next_line[0] == '\0')
		return (free_return_null(&next_line));
	return (next_line);
}
