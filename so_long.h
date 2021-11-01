#ifndef SO_LONG_H
#define SO_LONG_H
#include "minilibx_opengl/mlx.h"
#include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_img 
 { 
     void    *img_ptr; 
     char    *address; 
     int        bits_per_pixel; 
     int        line_size; 
     int        len_height;
     int        img_width;
     int        endian; 
     int        x;
     int        y;
 }                t_img;



typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_img   player;
    t_img   background;
    t_img   walls;
    t_img   exit;
    t_img   collection;
    t_img   remove_old_chr;
    int     game_speed;
}				t_vars;

void clean_old_image(t_vars *vars);
void change_chr_up(t_vars *vars);
void change_chr_down(t_vars *vars);
void change_chr_left(t_vars *vars);
int check_right(t_vars *vars);
void change_chr_right(t_vars *vars);
int check_left(t_vars *vars);
int check_up(t_vars *vars);
int check_down(t_vars *vars);
int		main(int argc, char **argv);
int close_a(int keycode, t_vars *vars);
int change_position(t_vars *vars, int keycode);
void create_walls(char *img_path, t_vars *vars,int x, int y);
int		check_up_down(char *data);
int		check_left_right(char *data);
void create_exit(char *img_path, t_vars *vars,int x, int y);
void create_win(t_vars *vars, int x, int y);
int check_exit(t_vars *vars,int keycode);
void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void	check_format(char *data);
void	error_txt(char *error_txt);
int check_block(t_vars *vars,int keycode);
void  create_fish_img(char *img_path, t_vars *vars, int x, int y);
void create_collection(char *img_path,t_vars *vars,int x, int y);
#endif
