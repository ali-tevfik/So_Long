/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 16:39:47 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/23 14:28:27 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_position(t_vars *vars, int a, int b)
{
	int	x;
	int	y;


	printf("x %d y %d maps %c\n\n",vars->player.x ,vars->player.y,vars->map_info.maps[0][0]);
	x = vars->player.x / 64;
	y = vars->player.y / 64;
	if (vars->map_info.maps[y - a][x - b] == '1')
		return (-1);
	else if (vars->map_info.maps[y - a][x - b] == 'E')
		return (-2);
	else if (vars->map_info.maps[y - a][x - b] == 'C')
		return (1);
	else
		return (0);
}
