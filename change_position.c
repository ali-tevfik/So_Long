/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:23:37 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 15:49:04 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void change_position(t_vars *vars, int keycode)
{
    clean_old_image(vars);
    //left
    if (keycode == 123)
    {
        vars->player.x = vars->player.x - vars->game_speed;
    }
    //right
    if (keycode == 124)
    {
         vars->player.x = vars->player.x + vars->game_speed;
    }
    //down
    if (keycode == 125)
    {
         vars->player.y = vars->player.y + vars->game_speed;
    }
    //up
    if (keycode == 126)
    {
         vars->player.y = vars->player.y - vars->game_speed;
    }
    
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img_ptr,vars->player.x , vars->player.y);
}


void clear_eat(t_vars *vars, int x, int y)
{
    vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,vars->player.img_width,vars->player.img_width);
    vars->remove_old_chr.address =  mlx_get_data_addr(vars->remove_old_chr.img_ptr, &vars->remove_old_chr.bits_per_pixel, &vars->remove_old_chr.line_size,
								&vars->remove_old_chr.endian);
    for (int a = 0; a < 32; a++)
    {
        for (int b = 0; b < 32; b++)
        {
             my_mlx_pixel_put(&vars->remove_old_chr,a,b, 0XADD8E6);
        }
        
    }
    mlx_put_image_to_window(vars->mlx , vars->win, vars->remove_old_chr.img_ptr, x, y);
}
void eat(t_vars *vars, int keycode)
{
    if (keycode == 123)
    {
        clear_eat(vars,vars->player.x - vars->game_speed, vars->player.y);
    }
    else if (keycode == 124)
    {
        clear_eat(vars,vars->player.x + vars->game_speed, vars->player.y);
    }
    else if (keycode == 125)
    {
        clear_eat(vars,vars->player.x, vars->player.y + vars->game_speed);
    }
    else if (keycode == 126)
    {
        clear_eat(vars,vars->player.x, vars->player.y - vars->game_speed);}
}