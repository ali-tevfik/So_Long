/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_maps.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:03:29 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/08 21:17:28 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_maps(t_vars *vars, int keycode)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = vars->player.x / 64;
	y = vars->player.y / 64;
	if (keycode == 123 || keycode == 0)
		vars->map_info.maps[y][x - 1] = '0';
	if (keycode == 124 || keycode == 2)
		vars->map_info.maps[y][x + 1] = '0';
	if (keycode == 125 || keycode == 1)
		vars->map_info.maps[y + 1][x] = '0';
	if (keycode == 126 || keycode == 13)
		vars->map_info.maps[y - 1][x] = '0';
}
