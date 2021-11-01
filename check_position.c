/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 16:39:47 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:55:34 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_up(t_vars *vars)
{
	if (vars->walls.y + vars->walls.len_height > vars->player.y -  vars->game_speed && vars->walls.y < vars->player.y -  vars->game_speed)
		{
			if (vars->walls.x < vars->player.x && vars->walls.x + vars->walls.len_height > vars->player.x)
				return (1);
			else if (vars->walls.x < vars->player.x + vars->player.len_height && vars->walls.x + vars->walls.len_height > vars->player.x + vars->player.len_height )
				return (1);
		}
    return (0);
}

int check_down(t_vars *vars)
{
    if (vars->walls.y < vars->player.y + vars->player.len_height +  vars->game_speed && (vars->walls.y + vars->walls.len_height > vars->player.y))
	{
		if (vars->walls.x < vars->player.x && vars->walls.x + vars->walls.len_height > vars->player.x)
				return (1);
		else if (vars->walls.x < vars->player.x + vars->player.len_height && vars->walls.x + vars->walls.len_height > vars->player.x + vars->player.len_height )
				return (1);
	}
		
    return (0);
}

int check_left(t_vars *vars)
{
	if (vars->walls.x + vars->walls.len_height > vars->player.x -  vars->game_speed && vars->walls.x < vars->player.x -  vars->game_speed)
	{
			if (vars->walls.y < vars->player.y && vars->walls.y + vars->walls.len_height > vars->player.y)
			return (1);
		else if (vars->walls.y < vars->player.y + vars->player.len_height && vars->walls.y + vars->walls.len_height > vars->player.y + vars->player.len_height)
			return (1);
	}
	
	return (0);
}

int check_right(t_vars *vars)
{
	if (vars->walls.x < vars->player.x + vars->game_speed + vars->player.len_height && vars->walls.x + vars->walls.len_height > vars->player.x + vars->game_speed + vars->player.len_height )
	{
		if (vars->walls.y < vars->player.y && vars->walls.y + vars->walls.len_height > vars->player.y)
			return (1);
		else if (vars->walls.y < vars->player.y + vars->player.len_height && vars->walls.y + vars->walls.len_height > vars->player.y + vars->player.len_height)
			return (1);
	}
    return (0);
}
