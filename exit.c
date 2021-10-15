/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/15 22:24:01 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "so_lang.h"

 t_vars create_exit(char *img_path, t_vars vars,int nerde)
{
	vars.exit.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.exit.img_width, &vars.exit.len_height);
	vars.exit.address = mlx_get_data_addr(vars.exit.img_ptr, &vars.exit.bits_per_pixel, &vars.exit.line_size,
										 &vars.exit.endian);
	vars.exit.x = 250;
    vars.exit.y = 250;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.exit.img_ptr, 250,250);
	return (vars);
}

int check_exit(t_vars vars)
{
printf("\n walls %d\n",vars.walls.len_height);
	printf("\n\nblok\n----------------------\nblok x  %d balik y %d\n",vars.exit.x ,vars.exit.y);
	printf("\n\nbalik\n----------------------\nbalik x min = %d max %d\n",vars.balik.x,vars.balik.x);
	printf("balik  y min = %d max %d\n\n",vars.balik.y,vars.balik.y);
  if (((vars.balik.x < vars.exit.x +64) && (vars.balik.x > vars.exit.x - 64) ) && ((vars.balik.y  < vars.exit.y + 64 ) && (vars.balik.y > vars.exit.y - 64)))
        return (0);
    return (1);
}