/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:36:34 by pcardoso          #+#    #+#             */
/*   Updated: 2020/01/28 17:55:25 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char *s, char c)
{
	size_t		end;
	size_t		start;
	char		**result;
	int			count_array;
	int			count_s;

	count_array = 0;
	count_s = 0;
	if (s[count_s] == '\0')
		result = (char **)ft_calloc(1, sizeof(char *));
	else if ((result = (char **)ft_calloc(ft_strlen(s), sizeof(char *))))
		while (s[count_s])
		{
			while (s[count_s] && s[count_s] == c)
				count_s++;
			start = count_s;
			while (s[count_s] && s[count_s] != c)
				count_s++;
			end = count_s;
			if (start < end)
				result[count_array++] = ft_substr(s, start, (end - start));
		}
	free(s);
	return (result);
}
