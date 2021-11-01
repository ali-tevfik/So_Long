/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:35:41 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 19:10:44 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_a(int keycode, t_vars *vars)
{
	int result;

	vars->counter++;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 124)
		result = check_position(vars,0,-1);
	else if (keycode == 123)
		result = check_position(vars,0,1);
	else if (keycode == 125)
		result = check_position(vars,-1,0);
	else if (keycode == 126)
		result = check_position(vars,1,0);

	if (result == 0)
			change_position(vars,keycode);
	else if (result == -1){}
	else if (result == -2)
	{
		printf("ate %d total %d\n",vars->ate,vars->total_eat);
		if (vars->ate == vars->total_eat)
		{
			change_position(vars,keycode);
			exit_game(vars);
		}
	}
	else if (result == 1)
	{
		change_maps(vars, keycode);
		vars->ate++;
		eat(vars, keycode);
		change_position(vars,keycode);
	}
}