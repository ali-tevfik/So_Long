/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 16:39:47 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/27 18:16:00 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

int check_up(t_vars *vars)
{
//  printf("check_right exit x %d %d y %d %d\n",vars->exit.x, vars->exit.x + vars->exit.len_height,vars->exit.y, vars->exit.y + vars->exit.len_height );
// 	printf("check_right old balik x %d %d y %d %d\n\n",vars->balik.x, vars->balik.x + vars->balik.len_height,vars->balik.y, vars->balik.y + vars->balik.len_height);
// 	printf("\nfirst %d > %d\n",vars->exit.y + vars->exit.len_height , vars->balik.y -  vars->game_speed);
// 	printf("\nright second if segmen %d < %d , %d > %d\n",vars->exit.x,vars->balik.x , vars->exit.x + vars->exit.len_height , vars->balik.x);
// 	printf("third if segment %d < %d && %d > %d\n\n",vars->exit.x , vars->balik.x + vars->balik.len_height ,vars->exit.x + vars->exit.len_height, vars->balik.x + vars->balik.len_height);
	
	
	if (vars->exit.y + vars->exit.len_height > vars->balik.y -  vars->game_speed && vars->exit.y < vars->balik.y -  vars->game_speed)
		{
			if (vars->exit.x < vars->balik.x && vars->exit.x + vars->exit.len_height > vars->balik.x)
				return (1);
			else if (vars->exit.x < vars->balik.x + vars->balik.len_height && vars->exit.x + vars->exit.len_height > vars->balik.x + vars->balik.len_height )
				return (1);
		}
    return (0);
}

int check_down(t_vars *vars)
{
	// printf("check_down exit x %d < %d \n",vars->exit.y , vars->balik.y + vars->balik.len_height +  vars->game_speed);
	// printf("first %d < %d , %d > %d \n",vars->exit.x , vars->balik.x , vars->exit.x + vars->exit.len_height , vars->balik.x);
	// printf("right second if segmen %d < %d , %d > %d\n\n\n",vars->exit.x , vars->balik.x + vars->balik.len_height , vars->exit.x + vars->exit.len_height , vars->balik.x + vars->balik.len_height );
	
    if (vars->exit.y < vars->balik.y + vars->balik.len_height +  vars->game_speed && (vars->exit.y + vars->exit.len_height > vars->balik.y))
	{
		if (vars->exit.x < vars->balik.x && vars->exit.x + vars->exit.len_height > vars->balik.x)
				return (1);
		else if (vars->exit.x < vars->balik.x + vars->balik.len_height && vars->exit.x + vars->exit.len_height > vars->balik.x + vars->balik.len_height )
				return (1);
	}
		
    return (0);
}

int check_left(t_vars *vars)
{
    printf("check_left exit x %d %d y %d %d\n",vars->exit.x, vars->exit.x + vars->exit.len_height,vars->exit.y, vars->exit.y + vars->exit.len_height );
	printf("check_left old balik x %d %d y %d %d\n\n",vars->balik.x, vars->balik.x + vars->balik.len_height,vars->balik.y, vars->balik.y + vars->balik.len_height);
	printf("if segmen %d , %d\n",vars->exit.x + vars->exit.len_height,vars->balik.x -  vars->game_speed);
	printf("game speed %d\n",vars->game_speed);
	printf("seconde if segment %d < %d || %d > %d\n\n\n",vars->exit.y ,vars->balik.y , vars->exit.y + vars->exit.len_height , vars->balik.y);
	
	if (vars->exit.x + vars->exit.len_height > vars->balik.x -  vars->game_speed && vars->exit.x < vars->balik.x -  vars->game_speed)
	{
		printf("gurdu");
			if (vars->exit.y < vars->balik.y && vars->exit.y + vars->exit.len_height > vars->balik.y)
			return (1);
		else if (vars->exit.y < vars->balik.y + vars->balik.len_height && vars->exit.y + vars->exit.len_height > vars->balik.y + vars->balik.len_height)
			return (1);
	}
	
	return (0);
}

int check_right(t_vars *vars)
{
    // printf("check_right exit x %d %d y %d %d\n",vars->exit.x, vars->exit.x + vars->exit.len_height,vars->exit.y, vars->exit.y + vars->exit.len_height );
	// printf("check_right old balik x %d %d y %d %d\n\n",vars->balik.x, vars->balik.x + vars->balik.len_height,vars->balik.y, vars->balik.y + vars->balik.len_height);
	// printf("\nfirst %d > %d\n",vars->exit.x , vars->balik.x + vars->game_speed + vars->balik.len_height);
	// printf("\nright second if segmen %d < %d , %d > %d\n",vars->exit.y , vars->balik.y , vars->exit.y + vars->exit.len_height , vars->balik.y);
	// printf("third if segment %d < %d && %d > %d\n\n",vars->exit.y , vars->balik.y + vars->balik.len_height , vars->exit.y + vars->exit.len_height , vars->balik.y + vars->balik.len_height);
	printf("game speed %d\n",vars->game_speed);
	if (vars->exit.x < vars->balik.x + vars->game_speed + vars->balik.len_height && vars->exit.x + vars->exit.len_height > vars->balik.x + vars->game_speed + vars->balik.len_height )
	{
		if (vars->exit.y < vars->balik.y && vars->exit.y + vars->exit.len_height > vars->balik.y)
			return (1);
		else if (vars->exit.y < vars->balik.y + vars->balik.len_height && vars->exit.y + vars->exit.len_height > vars->balik.y + vars->balik.len_height)
			return (1);
	}
    return (0);
}
