/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:23:37 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/05 19:03:05 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position(t_vars *vars, int keycode)
{
	clean_old_image(vars);
	if (keycode == 123 || keycode == 0)
		vars->player.x = vars->player.x - vars->game_speed;
	if (keycode == 124 || keycode == 2)
		vars->player.x = vars->player.x + vars->game_speed;
	if (keycode == 125 || keycode == 1)
		vars->player.y = vars->player.y + vars->game_speed;
	if (keycode == 126 || keycode == 13)
		vars->player.y = vars->player.y - vars->game_speed;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player.img_ptr, vars->player.x, vars->player.y);
}

void	clear_eat(t_vars *vars, int x, int y)
{
	int	a;
	int	b;

	a = 0;
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,
			vars->collection.img_width, vars->collection.len_height);
	vars->remove_old_chr.address = mlx_get_data_addr(
			vars->remove_old_chr.img_ptr,
			&vars->remove_old_chr.bits_per_pixel,
			&vars->remove_old_chr.line_size,
			&vars->remove_old_chr.endian);
	while (a < vars->collection.img_width)
	{
		b = 0;
		while (b < vars->collection.len_height)
		{
			my_mlx_pixel_put(&vars->remove_old_chr, a, b, 0XADD8E6);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->remove_old_chr.img_ptr, x, y);
}

void	eat(t_vars *vars, int keycode)
{
	if (keycode == 123 || keycode == 0)
		clear_eat(vars, vars->player.x - vars->game_speed, vars->player.y);
	else if (keycode == 124 || keycode == 2)
		clear_eat(vars, vars->player.x + vars->game_speed, vars->player.y);
	else if (keycode == 125 || keycode == 1)
		clear_eat(vars, vars->player.x, vars->player.y + vars->game_speed);
	else if (keycode == 126 || keycode == 13)
		clear_eat(vars, vars->player.x, vars->player.y - vars->game_speed);
}
