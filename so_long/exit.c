/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/29 20:03:48 by tevfik        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "so_lang.h"

 void create_exit(char *img_path, t_vars *vars,int nerde)
{
	t_img exit;
	
	exit.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &exit.img_width, &exit.len_height);
	exit.address = mlx_get_data_addr(exit.img_ptr, &exit.bits_per_pixel, &exit.line_size,
										 &exit.endian);
	exit.x = nerde;
    exit.y = nerde;
	mlx_put_image_to_window(vars->mlx, vars->win,exit.img_ptr, exit.x,exit.y);
	vars->exit.next = &exit;
	
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