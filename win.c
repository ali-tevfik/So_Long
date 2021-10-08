/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:40:57 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/08 21:02:17 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

t_vars create_win(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 1024, "Hello world!");
    vars.background.img_ptr = mlx_new_image(vars.mlx,1024,1024);
    vars.background.address =  mlx_get_data_addr(vars.background.img_ptr, &vars.background.bits_per_pixel, &vars.background.line_size,
								&vars.background.endian);
    for (int x = 0; x < 1024; x++)
    {
        for (int y = 0; y < 1024; y++)
        {
             my_mlx_pixel_put(&vars.background,x,y, 0XADD8E6);
        }
        
    }
    
    mlx_put_image_to_window(vars.mlx , vars.win, vars.background.img_ptr, 0, 0);
	return (vars);
}


void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char *dst;
	int offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}