/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/10/27 18:45:56 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"


void clean_old_image(t_vars *vars)
{
	
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,32,32);
    vars->remove_old_chr.address =  mlx_get_data_addr(vars->remove_old_chr.img_ptr, &vars->remove_old_chr.bits_per_pixel, &vars->remove_old_chr.line_size,
								&vars->remove_old_chr.endian);
    for (int x = 0; x < 32; x++)
    {
        for (int y = 0; y < 32; y++)
        {
             my_mlx_pixel_put(&vars->remove_old_chr,x,y, 0XADD8E6);
        }
        
    }
    mlx_put_image_to_window(vars->mlx , vars->win, vars->remove_old_chr.img_ptr, vars->balik.x, vars->balik.y );
}






void  create_fish_img(char *img_path, t_vars *vars, int yer)
{
	vars->balik.img_ptr = mlx_xpm_file_to_image(vars->mlx, img_path, &vars->balik.img_width, &vars->balik.len_height);
	vars->balik.address = mlx_get_data_addr(vars->balik.img_ptr, &vars->balik.bits_per_pixel, &vars->balik.line_size,
										 &vars->balik.endian);
	vars->balik.x = yer;
	vars->balik.y = yer;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.x , vars->balik.y);
}
void start_draw(int fd, int kac_adim)
{
	char *read_data;
	int i;
	int x;
	int img_width, img_height;
	char *relative_path = "./teapot.xpm";
	char *balik_path = "./fish_monster.xpm";
	char *exit_path = "./teapot.xpm";
	t_vars vars;
	int keycode; 
	int yer;

	yer = 600;
	x = 0;
	i = 1;
	vars.game_speed = 20;
	create_win(&vars);
	while (i > 0)
	{
		i = get_next_line(fd, &read_data);

		//printf("\n");
		x++;
	}
	for (int i = 0; i < 20; i++)
	{
		//printf("i = %d \n",i);
		create_walls(relative_path, &vars,i);
	}
	create_fish_img(balik_path, &vars,yer);
	create_exit(exit_path, &vars,300);

	create_exit(exit_path, &vars,200);
	create_exit(exit_path, &vars,400);
	printf("\nvars x = %d y = %d \n\n",vars.exit.x, vars.exit.y);
	mlx_key_hook(vars.win,close_a,&vars);
	if (keycode == 126)
	{
		yer += 5;
		keycode = mlx_key_hook(vars.win,close_a,&vars);
	}
	mlx_loop(vars.mlx);
}



int main(int argc, char **argv)
{
	char *read_data;
	int i;
	int fd;
	int control_map;
	int x;
	int fake_fd;
	int kac_adim;
	int len;
	int start_fd;

	len = 0;
	kac_adim = 0;
	control_map = 0;
	x = 0;
	read_data = NULL;
	fd = open(argv[1], O_RDONLY);
	fake_fd = open(argv[1], O_RDONLY);
	start_fd = open(argv[1], O_RDONLY);
	while (get_next_line(fake_fd, &read_data) > 0)
	{
		if (kac_adim != 0)
		{
			if (len != ft_strlen(read_data))
				return (-1);
		}
		else
			len = ft_strlen(read_data);
		kac_adim++;
	}

	read_data = NULL;
	argc = 0;
	i = 1;
	while (i > 0 && control_map == 0)
	{
		i = get_next_line(fd, &read_data);
		check_format(read_data);
		if (x == 0)
			control_map = check_up_down(read_data);
		if (kac_adim == x)
			control_map = check_up_down(read_data);
		else
			control_map = check_left_right(read_data);
		printf("\n");
		x++;
	}
	if (control_map == -1)
		printf("Map bozuk aq");
	else
		start_draw(start_fd, kac_adim);
}
