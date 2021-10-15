#ifndef SO_LANG_H
#define SO_LANG_H
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
    t_img   balik;
    t_img   background;
    t_img   walls;
    t_img   exit;
    t_img   remove_old_chr;
}				t_vars;




int		main(int argc, char **argv);
int close_a(int keycode, t_vars *vars);

t_vars create_walls(char *img_path, t_vars vars,int nerde);
int		check_up_down(char *data);
int		check_left_right(char *data);
void bilgi(t_vars *vars);
 t_vars create_exit(char *img_path, t_vars vars,int nerde);
t_vars create_win(t_vars vars);
int check_exit(t_vars vars);
void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void	check_format(char *data);
void	error_txt(char *error_txt);
#endif
