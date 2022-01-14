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

#ifndef SO_LONG_H
# define SO_LONG_H
# define RSIZE 20

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct t_map
{
	char	**game_map;
	int		position_x;
	int		position_y;
}	t_map;

int		main(int argc, char **argv);
char	*read_file(int fd, char *str_aux);
char	**create_board(char *filename);
int		validate_extension(char *filename);
void	build_board(char **game_map);
int		count_endline(char *str);
int		validate_file_exist(char *filename);
int		validate_file_presence(int argc);
int		count_endline(char *str);
int		validate_chars(t_map map);
int		invalid_char(char element);
void	free_map(t_map map);
int		shape_invalid(char **game_map);
int		check_rectangular_shape(int height, int row);
int		invalid_game_rules_e(t_map map);
int		invalid_game_rules_c(t_map map);
int		invalid_game_rules_p(t_map map);
int		invalid_top_wall(char **game_map, int max_countx);
int		invalid_right_wall(char **game_map, int cx, int cy, int max_cx);
int		invalid_low_wall(char **game_map, int countx, int county);
int		invalid_left_wall(char **game_map, int countx, int county);

#endif
