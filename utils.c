/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:40:57 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/03 22:31:33 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}

void	clean_old_image(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,
			vars->remove_old_chr.img_width, vars->remove_old_chr.img_width);
	vars->remove_old_chr.address = mlx_get_data_addr(
			vars->remove_old_chr.img_ptr,
			&vars->remove_old_chr.bits_per_pixel,
			&vars->remove_old_chr.line_size,
			&vars->remove_old_chr.endian);
	while (x < vars->player.len_height)
	{
		y = 0;
		while (y < vars->player.img_width)
		{
			my_mlx_pixel_put(&vars->remove_old_chr, x, y, 0XFFFFFF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->remove_old_chr.img_ptr,
		vars->player.x, vars->player.y);
	printf("endian %d height %d\n",vars->player.endian, vars->player.bits_per_pixel);
}

void	ft_put_img64(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->walls.img_ptr, 0,0);
}

void counter_draw(t_vars *vars){
	char *str = ft_itoa(vars->counter);
	ft_put_img64(vars);
	mlx_string_put(vars->mlx, vars->win, 25, 28, 0xFFFFFF, str);
	free(str);
}
