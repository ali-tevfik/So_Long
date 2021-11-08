/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 19:40:30 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/08 15:56:37 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_clikl(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit_game(vars);
}

void	exit_game(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->maps[i])
	{
		free(vars->maps[i]);
		i++;
	}
	if (vars->maps)
		free(vars->maps);
	exit (0);
}
