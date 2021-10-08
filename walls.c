/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:37:58 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/08 20:38:12 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

t_vars create_walls(char *img_path, t_vars vars,int nerde)
{
	vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.img.img_width, &vars.img.len_height);
	vars.img.address = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_size,
										 &vars.img.endian);
	printf("\n\n\nvar img %d %d \n\n",vars.img.len_height,vars.img.img_width);
	//x left
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, nerde * 64);
	//y up
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,  nerde * 64,0);
	//x right
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,960 , nerde * 64);
	// y down
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,  nerde * 64,960);
	return (vars);
}
