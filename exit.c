/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/19 16:45:35 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "so_lang.h"

 t_vars create_exit(char *img_path, t_vars vars,int nerde)
{
	vars.exit.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.exit.img_width, &vars.exit.len_height);
	vars.exit.address = mlx_get_data_addr(vars.exit.img_ptr, &vars.exit.bits_per_pixel, &vars.exit.line_size,
										 &vars.exit.endian);
	vars.exit.x = 250;
    vars.exit.y = 250;
	// for (int i = 0;i < 10;i++)
	// 	my_mlx_pixel_put(&vars.exit,i,i, 0XFFFFFF);
	// for (int i = 64;i > 54;i--)
	// 	my_mlx_pixel_put(&vars.exit,i,i, 0XDAF7A6 );
	// for (int i = 64;i > 44;i-=2)
	// 	my_mlx_pixel_put(&vars.exit,i,i/2, 0X581845);
	// for (int i = 0;i < 40;i+=2)
	// 	my_mlx_pixel_put(&vars.exit,i,i/2, 0XFF33FB);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.exit.img_ptr, 250,250);
	return (vars);
}

int check_exit(t_vars vars)
{
	//check left
	
    return (1);
}