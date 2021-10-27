/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:23:37 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/27 15:49:13 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

void change_chr_up(t_vars *vars)
{
    vars->balik.y = vars->exit.y + vars->exit.len_height;
}

void change_chr_down(t_vars *vars)
{
    vars->balik.y = vars->exit.y - vars->balik.len_height;
}

void change_chr_left(t_vars *vars)
{
    vars->balik.x = vars->exit.x + vars->exit.len_height;
}

void change_chr_right(t_vars *vars)
{
    vars->balik.x = vars->exit.x - vars->balik.len_height;
}