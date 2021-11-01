/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:55:51 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			else if (vars->player.x - vars->game_speed > vars->walls.len_height)
				vars->player.x -= vars->game_speed;
			else if (vars->player.x > vars->player.len_height)
				vars->player.x = vars->walls.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x,vars->player.y);
	}
	//right
	if (keycode == 124)
	{	
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_right(vars);
			else if (vars->player.x + vars->game_speed + vars->player.len_height < 1024 - 64)
				vars->player.x += vars->game_speed;
			else if (vars->player.x + vars->player.len_height < 1024 - 64)
				vars->player.x += 1024 - 64 - vars->player.x - vars->player.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x,vars->player.y);
		
	}
	//down
	if (keycode == 125)
	{
		
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_down(vars);
			else if(vars->player.y + vars->game_speed + vars->player.len_height < 1024 - 64)
				vars->player.y +=vars->game_speed;
			else if (vars->player.y + vars->player.len_height < 1024 - 64)
				vars->player.y += 1024 - 64 - vars->player.y - vars->player.len_height;	
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x,vars->player.y);
		
	}
	//up
	if (keycode == 126)
	{
			clean_old_image(vars);
			if (check_block(vars,keycode) == 1)
				change_chr_up(vars);
			else if(vars->player.y - vars->game_speed >  vars->walls.len_height)
				vars->player.y -= vars->game_speed;
			else if (vars->player.y > vars->walls.len_height)
				vars->player.y = vars->walls.len_height;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x,vars->player.y);
		
	}
}