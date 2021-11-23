/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_maps.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:03:29 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/23 13:43:42 by adoner        ########   odam.nl         */
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
	if (keycode == LEFT || keycode == A)
		vars->map_info.maps[y][x - 1] = '0';
	if (keycode == RIGHT || keycode == D)
		vars->map_info.maps[y][x + 1] = '0';
	if (keycode == DOWN || keycode == S)
		vars->map_info.maps[y + 1][x] = '0';
	if (keycode == UP || keycode == W)
		vars->map_info.maps[y - 1][x] = '0';
}
