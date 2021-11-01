/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:39:37 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"



void exit_game(t_vars *vars)
{
	int i;
	int a;

	a = 0;
	i = 0;
	printf("counter %d",vars->counter);
	while(vars->maps[i])
	{
		free(vars->maps[i]);
		i++;
	}
	free(vars->maps);
	exit (0);
	
}