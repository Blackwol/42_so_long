/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:48 by pcardoso          #+#    #+#             */
/*   Updated: 2022/02/01 04:44:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RSIZE 20

# define MLX_ERROR 1

# define RED 0xFF0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x006600
# define BLUE 0x0000FF

# define KEYCODE_EXIT 65307 //ESC
# define UP_ARROW 65362 //↑
# define DOWN_ARROW 65364 //↓
# define RIGHT_ARROW 65363 //→
# define LEFT_ARROW 65361 //←

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "./get_next_line.h"

typedef struct s_map
{
	char	**game_map;
	int		pos_x;
	int		pos_y;
	int		p_pos_x;
	int		p_pos_y;
	int		height;
	int		width;
	int		collectable_total;
	int		collected;
	int		p_count;
	int		e_count;
	int		moves;
}				t_map;

typedef struct s_img {
	void	*img_wall;
	char	*addr_wall;
	int		img_width_wall;
	int		img_height_wall;
	void	*img_floor;
	char	*addr_floor;
	int		img_width_floor;
	int		img_height_floor;
	void	*img_collectable;
	char	*addr_collect;
	int		img_width_collectable;
	int		img_height_collectable;
	void	*img_player;
	char	*addr_player;
	int		img_width_player;
	int		img_height_player;
	void	*img_exit;
	char	*addr_exit;
	int		img_width_exit;
	int		img_height_exit;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_img	*imgs;
}				t_data;

int		main(int argc, char **argv);
char	*read_file(int fd, char *str_aux);
char	**create_board(char *filename);
int		validate_extension(char *filename);
void	build_board(char **game_map);
int		validate_file_exist(char *filename);
int		validate_file_presence(int argc);
int		validate_chars(t_map *map);
int		invalid_char(char element);
int		validate_numbers_of_chars(char *str);
void	free_map(t_map *map);
int		shape_invalid(char **game_map);
int		check_rectangular_shape(int height, int row);
int		invalid_game_rules_e(t_map *map);
int		invalid_game_rules_c(t_map *map);
int		invalid_game_rules_p(t_map *map);
int		invalid_top_wall(char **game_map, int max_countx);
int		invalid_right_wall(char **game_map, int cx, int cy, int max_cx);
int		invalid_low_wall(char **game_map, int countx, int county);
int		invalid_left_wall(char **game_map, int countx, int county);
int		start_game(t_map map);

void	set_hooks(t_data *data);

int		get_key_press(int keysym, t_data *data);
int		close_window(t_data *data);
int		render_map(t_data *data);

void	generate_imgs(t_data *data);
void	generate_wall(t_data *data);
void	generate_floor(t_data *data);
void	generate_collectable(t_data *data);

void	generate_exit(t_data *data);
void	generate_player(t_data *data);

int		render_map(t_data *data);
void	put_img_in_window(t_data *data, int img_x, int img_y);

void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);
void	check_can_exit(t_data *data);

void	init_data_vars(t_data *data);
void	init_map_vars(t_map *map);

void	increase_chars_count(t_map *map);

#endif
