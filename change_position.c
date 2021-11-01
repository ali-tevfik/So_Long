/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:23:37 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:51:06 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void change_chr_up(t_vars *vars)
{
    vars->player.y = vars->walls.y + vars->walls.len_height;
}

void change_chr_down(t_vars *vars)
{
    vars->player.y = vars->walls.y - vars->player.len_height;
}

void change_chr_left(t_vars *vars)
{
    vars->player.x = vars->walls.x + vars->walls.len_height;
}

void change_chr_right(t_vars *vars)
{
    vars->player.x = vars->walls.x - vars->player.len_height;
}