/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/01 19:10:25 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void clean_old_image(t_vars *vars)
{
	
	vars->remove_old_chr.img_ptr = mlx_new_image(vars->mlx,vars->player.img_width,vars->player.img_width);
    vars->remove_old_chr.address =  mlx_get_data_addr(vars->remove_old_chr.img_ptr, &vars->remove_old_chr.bits_per_pixel, &vars->remove_old_chr.line_size,
								&vars->remove_old_chr.endian);
    for (int x = 0; x < 32; x++)
    {
        for (int y = 0; y < 32; y++)
        {
             my_mlx_pixel_put(&vars->remove_old_chr,x,y, 0XADD8E6);
        }
        
    }
    mlx_put_image_to_window(vars->mlx , vars->win, vars->remove_old_chr.img_ptr, vars->player.x, vars->player.y );
}









void start_draw(int fd, int kac_adim, int xx, int y)
{
	char *read_data;
	int i;
	int x;
	int img_width, img_height;
	char *relative_path = "image/walls.xpm";
	char *player_path = "image/fish.xpm";
	char *colletief_path = "image/smal_water_girl.xpm";
	char *exit_path = "image/fish_klein.xpm";
	t_vars vars;
	int a;

	vars.counter = 0;
	vars.maps = (char**)malloc(sizeof(vars.maps) * kac_adim); 
	x = 0;
	i = 1;
	vars.game_speed = 64;
	vars.ate = 0;
	vars.total_eat = 0;
	create_win(&vars,xx,y);
	while (i > 0)
	{
		i = get_next_line(fd, &read_data);
		a = 0;
		vars.maps[x] = ft_strdup(read_data);
		if (vars.maps[x] == NULL)
			exit_game(&vars);
		while(read_data[a])
		{
			if (read_data[a] == '1')
				create_walls(relative_path,&vars,a,x);
			else if (read_data[a] == 'P')
 				create_fish_img(player_path,&vars,a,x);
			else if (read_data[a] == 'C')
				create_collection(colletief_path,&vars,a,x);
			else if (read_data[a] == 'E')
				create_exit(exit_path, &vars,a,x);
			a++;
		}
		x++;
	}
	vars.maps[x] = NULL;
	mlx_key_hook(vars.win,close_a,&vars);
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
				control_map = -1;
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
		start_draw(start_fd, kac_adim, len,kac_adim);
}
