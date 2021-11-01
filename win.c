/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:40:57 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/01 13:56:01 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




void    my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char    *dst;
    int     offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}