/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 19:50:44 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	result_func(t_vars *vars, int keycode, int result)
{
	if (result == 0)
		change_position(vars, keycode);
	else if (result == -1)
	{}
	else if (result == -2)
	{
		if (vars->ate == vars->total_eat)
		{
			change_position(vars, keycode);
			exit_game(vars);
		}
	}
	else if (result == 1)
	{
		change_maps(vars, keycode);
		vars->ate++;
		eat(vars, keycode);
		change_position(vars, keycode);
	}
}

int	close_a(int keycode, t_vars *vars)
{
	int	result;

	vars->counter++;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit_game(vars);
	}
	if (keycode == 124)
		result = check_position(vars, 0, -1);
	else if (keycode == 123)
		result = check_position(vars, 0, 1);
	else if (keycode == 125)
		result = check_position(vars, -1, 0);
	else if (keycode == 126)
		result = check_position(vars, 1, 0);
	result_func(vars, keycode, result);
}
