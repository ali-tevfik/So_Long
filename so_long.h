/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:26:11 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/08 16:20:36 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		len_height;
	int		img_width;
	int		endian;
	int		x;
	int		y;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	player;
	t_img	background;
	t_img	walls;
	t_img	exit;
	t_img	collection;
	t_img	remove_old_chr;
	t_img	open_exit;
	char	**maps;
	int		game_speed;
	int		total_eat;
	int		counter;
	int		ate;
}			t_vars;

typedef struct s_map
{
	int		player;
	int		collection;
	int		exit;
}			t_map;

void	change_maps(t_vars *vars, int keycode);
int		check_error_and_write(t_map maps);
void	change_position(t_vars *vars, int keycode);
int		main(int argc, char **argv);
int		close_a(int keycode, t_vars *vars);
int		check_position(t_vars *vars, int a, int b);
void	create_walls(t_vars *vars, int x, int y);
int		check_up_down(char *data);
int		check_left_right(char *data);
void	create_exit(t_vars *vars, int x, int y);
void	create_win(t_vars *vars, int x, int y);
int		check_exit(t_vars *vars, int keycode);
void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void	check_format(char *data);
void	error_txt(char *error_txt);
void	exit_game(t_vars *vars);
void	create_fish_img(t_vars *vars, int x, int y);
void	create_collection(t_vars *vars, int x, int y);
void	eat(t_vars *vars, int keycode);
int		check_len_maps(int argc, char **argv, int fd);
int		step_find(char **argv);
int		line_len(char **argv);
int		check_maps(char **argv);
int		close_clikl(t_vars *vars);
void	counter_draw(t_vars *vars);
#endif
