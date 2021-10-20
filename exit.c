/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 18:38:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/10/20 17:04:34 by adoner        ########   odam.nl         */
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
int check_exit(t_vars vars)
{
	printf("\n balik konum x  = %d-%dy = %d-%d\n",vars.balik.x,vars.balik.x + 32,vars.balik.y, vars.balik.y + 32);
	printf("duvar konum x = %d-%d  y= %d-%d\n\n\n",vars.exit.x,vars.exit.x + 64,vars.exit.y,vars.exit.y + 64);
	// allen left up chrachter check
	if ((vars.balik.x > 249 || vars.balik.x + 32 > 249) && (vars.balik.x < 315 || vars.balik.x + 32 < 315))
	{
		if ((vars.balik.y > 249  || vars.balik.y + 32 > 249) && (vars.balik.y < 315 || vars.balik.y + 32 < 315))
			return (0);
	}
    return (1);
}

void change_position(t_vars *vars, int keycode)
{
	//left
	if (keycode == 123)
		vars->balik.x = vars->exit.x + 65;
	//right
	else if (keycode == 124)
		vars->balik.x = vars->exit.x - 32;
	//up
	else if (keycode == 126)
		vars->balik.y = vars->exit.y + 64;
	//down
	else if(keycode == 125)
		vars->balik.y = vars->exit.y - 32;
}
int check_block(t_vars *vars, int keycode)
{
	if (keycode == 123)
		vars->balik.x -= vars->game_speed;
	else if (keycode == 124)
		vars->balik.x += vars->game_speed;
	else if(keycode == 125)
		vars->balik.y += vars->game_speed;
	else 
		vars->balik.y -=  vars->game_speed;
	int i = check_exit(*vars);
	if (keycode == 123)
			vars->balik.x +=vars->game_speed;
		else if (keycode == 124)
			vars->balik.x -= vars->game_speed;
		else if (keycode == 125)
			vars->balik.y -= vars->game_speed;
		else
			vars->balik.y += vars->game_speed;
	if (i == 1)
	{
		printf("GIRDI\n");
		return (0);
		}
	return (1);
	
}