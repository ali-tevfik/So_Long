/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 13:47:45 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/10 12:07:48 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_player(t_vars *vars, int x, int y)
{
	char	*img_path;

	img_path = "image/exit.xpm";
	vars->player.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path,
			&vars->player.img_width, &vars->player.len_height);
	vars->player.address = mlx_get_data_addr(vars->player.img_ptr,
			&vars->player.bits_per_pixel,
			&vars->player.line_size,
			&vars->player.endian);
	vars->player.x = x * vars->walls.img_width;
	vars->player.y = y * vars->walls.len_height;
	mlx_put_image_to_window (vars->mlx, vars->win,
		vars->player.img_ptr, vars->player.x, vars->player.y);
	vars->counter = 0;
	counter_draw(vars);
}

void	create_collection(t_vars *vars, int x, int y)
{
	char	*img_path;

	img_path = "image/ball.xpm";
	vars->collection.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path,
			&vars->collection.img_width, &vars->collection.len_height);
	vars->collection.address = mlx_get_data_addr(vars->collection.img_ptr,
			&vars->collection.bits_per_pixel,
			&vars->collection.line_size,
			&vars->collection.endian);
	vars->collection.x = x * vars->walls.len_height;
	vars->collection.y = y * vars->walls.len_height;
	vars->total_eat++;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->collection.img_ptr, vars->collection.x, vars->collection.y);
}

void	create_exit(t_vars *vars, int x, int y)
{
	char	*img_path;

	img_path = "image/stone.xpm";
	vars->exit.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path,
			&vars->exit.img_width, &vars->exit.len_height);
	vars->exit.address = mlx_get_data_addr(vars->exit.img_ptr,
			&vars->exit.bits_per_pixel,
			&vars->exit.line_size, &vars->exit.endian);
	vars->exit.x = x * vars->walls.len_height;
	vars->exit.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img_ptr,
		vars->exit.x, vars->exit.y);
}

void	create_walls(t_vars *vars, int x, int y)
{
	char	*img_path;

	img_path = "image/walls.xpm";
	vars->walls.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path,
			&vars->walls.img_width, &vars->walls.len_height);
	vars->walls.address = mlx_get_data_addr(vars->walls.img_ptr,
			&vars->walls.bits_per_pixel,
			&vars->walls.line_size, &vars->walls.endian);
	vars->walls.x = x * vars->walls.len_height;
	vars->walls.y = y * vars->walls.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->walls.img_ptr,
		vars->walls.x, vars->walls.y);
}

void	create_win(t_vars *vars, int x, int y)
{
	int	a;
	int	b;

	a = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x * 64, (y + 1) * 64, "POKEMONN!");
	vars->background.img_ptr = mlx_new_image(vars->mlx, x * 64, y * 64);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
	while (a < x * 64)
	{
		b = 0;
		while (b < y * 64)
		{
			my_mlx_pixel_put(&vars->background, a, b, 0XADD8E6);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, 0, 0);
}
