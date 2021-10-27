/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/27 18:16:33 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

int close_a(int keycode, t_vars *vars)
{
	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//left
	if (keycode == 123)
	{
			clean_old_image(vars);
			if (check_block(vars, keycode) == 1)
				change_chr_left(vars);
			else if (vars->balik.x - vars->game_speed > vars->walls.len_height)
				vars->balik.x -= vars->game_speed;
			else if (vars->balik.x > vars->balik.len_height)
				vars->balik.x = vars->walls.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
	}
	//right
	if (keycode == 124)
	{	
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_right(vars);
			else if (vars->balik.x + vars->game_speed + vars->balik.len_height < 1024 - 64)
				vars->balik.x += vars->game_speed;
			else if (vars->balik.x + vars->balik.len_height < 1024 - 64)
				vars->balik.x += 1024 - 64 - vars->balik.x - vars->balik.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
	//down
	if (keycode == 125)
	{
		
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_down(vars);
			else if(vars->balik.y + vars->game_speed + vars->balik.len_height < 1024 - 64)
				vars->balik.y +=vars->game_speed;
			else if (vars->balik.y + vars->balik.len_height < 1024 - 64)
				vars->balik.y += 1024 - 64 - vars->balik.y - vars->balik.len_height;	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
	//up
	if (keycode == 126)
	{
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_up(vars);
			else if(vars->balik.y - vars->game_speed >  vars->walls.len_height)
				vars->balik.y -= vars->game_speed;
			else if (vars->balik.y > vars->walls.len_height)
				vars->balik.y = vars->walls.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x,vars->balik.y);
		
	}
}