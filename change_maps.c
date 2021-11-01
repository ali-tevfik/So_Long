/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_maps.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:03:29 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 18:51:37 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void change_maps(t_vars *vars, int keycode)
{
    int x;
    int y;
    int i;

    i = 0;
    x = vars->player.x / 64;
    y = vars->player.y / 64;
    if (keycode == 123)
    {
       vars->maps[y][x - 1] = '0';
    }
    else if (keycode == 124)
    {
        vars->maps[y][x + 1] = '0';
    }
    else if (keycode == 125)
    {
        vars->maps[y + 1][x] = '0';
    }
    else if (keycode == 126)
    {
        vars->maps[y -1][x] = '0';
    }
}