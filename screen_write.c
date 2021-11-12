/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_write.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 11:23:54 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/12 10:51:58 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img64(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->walls.img_ptr, 0, 0);
}

void	counter_draw(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->counter);
	if (!str)
		exit_game(vars);
	ft_put_img64(vars);
	mlx_string_put(vars->mlx, vars->win, 25, 28, 0xFFFFFF, str);
	free(str);
}
