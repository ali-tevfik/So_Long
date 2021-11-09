/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:40:57 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/09 11:23:48 by adoner        ########   odam.nl         */
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
	int	a;
	int	b;

	a = 0;
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,
			vars->player.img_width, vars->player.len_height);
	vars->remove_old_chr.address = mlx_get_data_addr(
			vars->remove_old_chr.img_ptr,
			&vars->remove_old_chr.bits_per_pixel,
			&vars->remove_old_chr.line_size,
			&vars->remove_old_chr.endian);
	while (a < vars->player.img_width)
	{
		b = 0;
		while (b < vars->player.len_height)
		{
			my_mlx_pixel_put(&vars->remove_old_chr, a, b, 0XADD8E6);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->remove_old_chr.img_ptr, vars->player.x, vars->player.y);
}
