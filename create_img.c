/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 13:47:45 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:55:38 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  create_fish_img(char *img_path, t_vars *vars, int x, int y)
{
	vars->player.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &vars->player.img_width, &vars->player.len_height);
	vars->player.address = mlx_get_data_addr(vars->player.img_ptr, &vars->player.bits_per_pixel, &vars->player.line_size,
										 &vars->player.endian);
	vars->player.x = x * vars->walls.len_height;
	vars->player.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x , vars->player.y);
}


void create_collection(char *img_path,t_vars *vars,int x, int y)
{
	vars->player.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &vars->player.img_width, &vars->player.len_height);
	vars->player.address = mlx_get_data_addr(vars->player.img_ptr, &vars->player.bits_per_pixel, &vars->player.line_size,
										 &vars->player.endian);
	vars->player.x = x * vars->walls.len_height;
	vars->player.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x , vars->player.y);
}

 void create_exit(char *img_path, t_vars *vars,int x, int y)
{
	t_img walls;
	
	walls.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &walls.img_width, &walls.len_height);
	walls.address = mlx_get_data_addr(walls.img_ptr, &walls.bits_per_pixel, &walls.line_size,
										 &walls.endian);
	walls.x = x * vars->walls.len_height;
    walls.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win,walls.img_ptr, walls.x,walls.y);
}

void create_walls(char *img_path, t_vars *vars,int x, int y)
{
	vars->walls.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &vars->walls.img_width, &vars->walls.len_height);
	vars->walls.address = mlx_get_data_addr(vars->walls.img_ptr, &vars->walls.bits_per_pixel, &vars->walls.line_size,
										 &vars->walls.endian);

	vars->walls.x = x * vars->walls.len_height;
	vars->walls.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->walls.img_ptr, vars->walls.x, vars->walls.y);
}

void    create_win(t_vars *vars, int x, int y)
{
    int a;
    int b;

    a = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x * 64, y * 64, "Hello world!");
    vars->background.img_ptr = mlx_new_image(vars->mlx,x * 64, y * 64);
    vars->background.address =  mlx_get_data_addr(vars->background.img_ptr, &vars->background.bits_per_pixel, &vars->background.line_size,
								&vars->background.endian);
    while (a < x * 64)
    {
        b = 0;
        while (b < y * 64)
        {
            my_mlx_pixel_put(&vars->background,a,b, 0XADD8E6);
            b++;
        }
        a++;
    }    
    mlx_put_image_to_window(vars->mlx , vars->win, vars->background.img_ptr, 0, 0);
}