/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:12:51 by pcardoso          #+#    #+#             */
/*   Updated: 2022/01/30 22:30:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_newline(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*n_str;

	i = 0;
	j = 0;
	n_str = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 2);
	if (!(n_str))
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\n')
		n_str[i++] = s2[j++];
	n_str[i] = '\n';
	n_str[i + 1] = '\0';
	free(s1);
	return (n_str);
}

char	*gnl_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	i = 0;
	size = gnl_strlen(s1);
	tmp = malloc(sizeof(char) * size + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t	gnl_strlen(const char *str)
{
	size_t	char_count;

	char_count = 0;
	while (str[char_count] != '\0')
	{
		char_count++;
	}
	return (char_count);
}

void	*gnl_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*n_dst;
	const char		*n_src;

	i = 0;
	n_dst = dst;
	n_src = src;
	if (n_dst > n_src)
	{
		i = n;
		while (i > 0)
		{
			n_dst[i - 1] = n_src[i - 1];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			n_dst[i] = n_src[i];
			i++;
		}
	}
	return (dst);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*n_str;

	i = 0;
	j = 0;
	n_str = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!(n_str))
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		n_str[i++] = s2[j++];
	n_str[i] = '\0';
	free(s1);
	return (n_str);
}
