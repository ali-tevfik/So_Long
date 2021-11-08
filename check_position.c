/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 16:39:47 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/08 21:16:05 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_position(t_vars *vars, int a, int b)
{
	int	x;
	int	y;

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
