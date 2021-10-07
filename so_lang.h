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
    t_img   img;
}				t_vars;




int		main(int argc, char **argv);
int		check_up_down(char *data);
int		check_left_right(char *data);
void	check_format(char *data);
void	error_txt(char *error_txt);
#endif
