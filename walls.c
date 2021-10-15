/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:37:58 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/11 17:36:21 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

t_vars create_walls(char *img_path, t_vars vars,int nerde)
{
	vars.walls.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.walls.img_width, &vars.walls.len_height);
	vars.walls.address = mlx_get_data_addr(vars.walls.img_ptr, &vars.walls.bits_per_pixel, &vars.walls.line_size,
										 &vars.walls.endian);
	printf("\n\n\nwallet  %d %d \n\n",vars.walls.len_height,vars.walls.img_width);
	//x left
	mlx_put_image_to_window(vars.mlx, vars.win, vars.walls.img_ptr, 0, nerde * 64);
	//y up
	mlx_put_image_to_window(vars.mlx, vars.win, vars.walls.img_ptr,  nerde * 64,0);
	//x right
	mlx_put_image_to_window(vars.mlx, vars.win, vars.walls.img_ptr,960 , nerde * 64);
	// y down
	mlx_put_image_to_window(vars.mlx, vars.win, vars.walls.img_ptr,  nerde * 64,960);
	return (vars);
}
