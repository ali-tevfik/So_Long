/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/20 16:42:12 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

void bilgi(t_vars *vars)
 {
	
// 	printf("\n\nimg_ptr = %d,\nbit_pxl %d\nline_size %d\nlen_heidht %d\nimg_width = %d\n endian = %d\nx = %d\ny=%d\n\n",(int*)vars->balik.img_ptr,vars->balik.line_size,vars->balik.len_height,vars->balik.img_width,vars->balik.endian,vars->balik.x,vars->balik.y);
	
}

int close_a(int keycode, t_vars *vars)
{
	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//left
	printf("key %d",keycode);
	if (keycode == 123)
	{
			clean_old_image(vars);
			if (check_block(vars, keycode) == 1)
			{change_position(vars, keycode);
	
			}
			else if (vars->balik.x - vars->game_speed > vars->walls.len_height)
				vars->balik.x -= vars->game_speed;
			else if (vars->balik.x > vars->balik.len_height  && check_exit(*vars) != 0)
				vars->balik.x = vars->walls.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
		
	}
	//right
	if (keycode == 124)
	{	
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
			{
change_position(vars, keycode);
			}
			else if (vars->balik.x + vars->game_speed + vars->balik.len_height < 1024 - 64)
				vars->balik.x += vars->game_speed;
			else if (vars->balik.x + vars->balik.len_height < 1024 - 64  && check_exit(*vars) != 0)
				vars->balik.x += 1024 - 64 - vars->balik.x - vars->balik.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
	//down
	if (keycode == 125)
	{
		
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
			{
change_position(vars, keycode);
			}
			else if(vars->balik.y + vars->game_speed + vars->balik.len_height < 1024 - 64)
				vars->balik.y +=vars->game_speed;
			else if (vars->balik.y + vars->balik.len_height < 1024 - 64  && check_exit(*vars) != 0)
				vars->balik.y += 1024 - 64 - vars->balik.y - vars->balik.len_height;	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
	//up
	if (keycode == 126)
	{
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
			{change_position(vars, keycode);
			}
			else if(vars->balik.y - vars->game_speed >  vars->walls.len_height)
				vars->balik.y -= vars->game_speed;
			else if (vars->balik.y > vars->walls.len_height  && check_exit(*vars) != 0)
				vars->balik.y = vars->walls.len_height;
				
			printf("after position %d",vars->balik.y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
}