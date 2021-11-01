/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 19:40:30 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 19:41:08 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_vars *vars)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (vars->maps[i])
	{
		free(vars->maps[i]);
		i++;
	}
	free(vars->maps);
	exit (0);
}
