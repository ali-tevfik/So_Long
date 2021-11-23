/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/23 14:59:32 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	create_new_exit(t_vars *vars)
{
	char	*img_path;

	img_path = "image/ladder.xpm";
	vars->open_exit.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path,
			&vars->open_exit.img_width, &vars->open_exit.len_height);
	vars->open_exit.address = mlx_get_data_addr(vars->open_exit.img_ptr,
			&vars->open_exit.bits_per_pixel,
			&vars->open_exit.line_size, &vars->open_exit.endian);
	vars->open_exit.x = vars->exit.x;
	vars->open_exit.y = vars->exit.y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->open_exit.img_ptr,
		vars->open_exit.x, vars->open_exit.y);
}

void	clean_old_exit(t_vars *vars)
{
	int	a;
	int	b;

	a = 0;
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,
			vars->exit.img_width, vars->exit.len_height);
	vars->remove_old_chr.address = mlx_get_data_addr(
			vars->remove_old_chr.img_ptr,
			&vars->remove_old_chr.bits_per_pixel,
			&vars->remove_old_chr.line_size,
			&vars->remove_old_chr.endian);
	while (a < vars->exit.img_width)
	{
		b = 0;
		while (b < vars->exit.len_height)
		{
			my_mlx_pixel_put(&vars->remove_old_chr, a, b, 0XADD8E6);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->remove_old_chr.img_ptr, vars->exit.x, vars->exit.y);
	create_new_exit(vars);
}

void	write_terminal(t_vars *vars, int result)
{
	if (result == 1 || result == 0)
	{
		vars->counter++;
		counter_draw(vars);
		printf("step %d\n", vars->counter);
	}
	else if (vars->ate == vars->total_eat && result == -2)
	{
		printf("\n\n////////////////////////////////////////////////////\n");
		printf("////////////////////////////////////////////////////\n");
		printf("////////////////////////////////////////////////////\n");
		printf("////////////  Finished Game.  //////////////////////\n");
		printf("////////////  Total steps = %d  ////////////////////\n",
			vars->counter);
		printf("////////////////////////////////////////////////////\n");
		printf("////////////////////////////////////////////////////\n");
		printf("////////////////////////////////////////////////////\n\n\n");
	}
}

void	result_func(t_vars *vars, int keycode, int result)
{
	if (result == 0)
		change_position(vars, keycode);
	else if (result == -2)
	{
		if (vars->ate == vars->total_eat)
		{
			change_position(vars, keycode);
			write_terminal(vars, result);
			exit_game(vars);
		}
	}
	else if (result == 1)
	{
		change_maps(vars, keycode);
		vars->ate++;
		printf("%d ate\n", vars->ate);
		eat(vars, keycode);
		if (vars->ate == vars->total_eat)
			printf("all ate\nopen exit\n");
		if (vars->ate == vars->total_eat)
			clean_old_exit(vars);
		change_position(vars, keycode);
	}
	write_terminal(vars, result);
}

int	click_button(int keycode, t_vars *vars)
{
	int	result;

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit_game(vars);
	}
	if (keycode == RIGHT || keycode == D)
		result = check_position(vars, 0, -1);
	else if (keycode == LEFT || keycode == A)
		result = check_position(vars, 0, 1);
	else if (keycode == DOWN || keycode == S)
		result = check_position(vars, -1, 0);
	else if (keycode == UP || keycode == W)
		result = check_position(vars, 1, 0);
	else
		return (0);
	result_func(vars, keycode, result);
	return (0);
}
