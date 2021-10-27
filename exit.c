/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/27 18:12:57 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "so_lang.h"

 void create_exit(char *img_path, t_vars *vars,int nerde)
{
	t_img img;
	vars->exit.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &vars->exit.img_width, &vars->exit.len_height);
	vars->exit.address = mlx_get_data_addr(vars->exit.img_ptr, &vars->exit.bits_per_pixel, &vars->exit.line_size,
										 &vars->exit.endian);
	vars->exit.x = 100;
    vars->exit.y = 700;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img_ptr, vars->exit.x,vars->exit.y);

	// img.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &img.img_width, &img.len_height);
	// img.address = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_size,
	// 									 &img.endian);
	// img.x = 200;
    // img.y = 100;
	// mlx_put_image_to_window(vars->mlx, vars->win,img.img_ptr, img.x,img.y);
	// vars->next = &img;
	// vars->next = NULL;
}


int check_block(t_vars *vars, int keycode)
{
	int result;
	if (keycode == 123)
	{
		result = check_left(vars);
	}
	else if (keycode == 124)
	{
		result = check_right(vars);
	}
	else if(keycode == 125)
	{
		result = check_down(vars);
	}
	else 
	{
		result = check_up(vars);
	}
	return (result);
	
}