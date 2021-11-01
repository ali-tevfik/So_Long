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



int check_block(t_vars *vars, int keycode)
{
	int result;
	if (keycode == 123)
	{
		result = check_left(vars);
	}
	else if (keycode == 124)
	{
		result = check_right(vars);
	}
	else if(keycode == 125)
	{
		result = check_down(vars);
	}
	else 
	{
		result = check_up(vars);
	}
	return (result);
	
}