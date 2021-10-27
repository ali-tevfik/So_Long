/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/26 15:09:23 by adoner        ########   odam.nl         */
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

// ik moet alles hoek chek

// int change_position(t_vars *vars, int keycode)
// {
// 	printf("change postion caleld!\n\n");
// 	//left
// 	if (keycode == 123)
// 		return (vars->exit.x + 65);
// 	//right
// 	else if (keycode == 124)
// 		return (vars->exit.x - 32);
// 	//up
// 	else if (keycode == 126)
// 		return (vars->exit.y + 64);
// 	//down
// 	else if(keycode == 125)
// 	return (vars->exit.y - 32);
// }
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