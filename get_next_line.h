/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:05:16 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/02 16:58:43 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
void	*gnl_memmove(void *dst, const void *src, size_t n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char *s2);
char	*strjoin_newline(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
