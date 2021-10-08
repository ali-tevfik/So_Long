/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/08 22:11:19 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

void bilgi(t_vars *vars)
 {
	
// 	printf("\n\nimg_ptr = %d,\nbit_pxl %d\nline_size %d\nlen_heidht %d\nimg_width = %d\n endian = %d\nx = %d\ny=%d\n\n",(int*)vars->balik.img_ptr,vars->balik.line_size,vars->balik.len_height,vars->balik.img_width,vars->balik.endian,vars->balik.x,vars->balik.y);
	
}

int close_a(int keycode, t_vars *vars)
{
	printf("\n\n\nHello from key_hook! %d vars mlx = %s win = %s\n", keycode, vars->mlx, vars->win);

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//up
	if (keycode == 126)
	{
		bilgi(vars);
		clean_old_image(vars);
		if (vars->balik.x - 15 > vars->walls.len_height)
			vars->balik.x -= 15;
		else if (vars->balik.x > vars->balik.len_height)
			vars->balik.x = vars->walls.len_height;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
		printf("duvar %d", vars->walls.len_height);
	}
	//down
	if (keycode == 125)
	{	
		bilgi(vars);
		clean_old_image(vars);
		if (vars->balik.x + 15 + vars->balik.len_height < 1024 - 64)
			vars->balik.x += 15;
		else if (vars->balik.x + vars->balik.len_height < 1024 - 64)
			vars->balik.x += 1024 - 64 - vars->balik.x - vars->balik.len_height;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
		
	}
	//right
	if (keycode == 124)
	{
		bilgi(vars);
		clean_old_image(vars);
		if(vars->balik.y + 15 + vars->balik.len_height < 1024 - 64)
			vars->balik.y +=15;
		else if (vars->balik.y + vars->balik.len_height < 1024 - 64)
			vars->balik.y += 1024 - 64 - vars->balik.y - vars->balik.len_height;
		
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
	}
	//left
	if (keycode == 123)
	{
		bilgi(vars);
		clean_old_image(vars);
		if(vars->balik.y - 15 >  vars->walls.len_height)
			vars->balik.y -= 15;
		else if (vars->balik.y > vars->walls.len_height)
			vars->balik.y = vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
	}
}