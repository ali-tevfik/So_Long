/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/10/07 18:11:32 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char *dst;
	int offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}
void clean_old_image(t_vars *vars)
{
	
	char *balik_path = "./fish_monster.xpm";
	for(int i = 0; i<65;i++)
	{
		for (int y = 0; y<65;y++)
			my_mlx_pixel_put(&vars->balik, i	, y, 0x000000);
		
			
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
	
}

int close_a(int keycode, t_vars *vars)
{
	printf("\n\n\nHello from key_hook! %d vars mlx = %s win = %s\n", keycode, vars->mlx, vars->win);

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//up
	if (keycode == 126)
	{
		clean_old_image(vars);
		if (vars->balik.x - 15 > vars->img.len_height)
			vars->balik.x -= 15;
		else if (vars->balik.x > vars->balik.len_height)
			vars->balik.x = vars->img.len_height;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
		printf("duvar %d", vars->img.len_height);
	}
	//down
	if (keycode == 125)
	{	
		//clean_old_image(vars);
		if (vars->balik.x + 15 + vars->balik.len_height < 1024 - 64)
			vars->balik.x += 15;
		else if (vars->balik.x + vars->balik.len_height < 1024 - 64)
			vars->balik.x += 1024 - 64 - vars->balik.x - vars->balik.len_height;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
		
	}
	//right
	if (keycode == 124)
	{
		printf("\n\nright %d height %d\n\n",vars->balik.y,vars->balik.len_height);
		//clean_old_image(vars);
		if(vars->balik.y + 15 + vars->balik.len_height < 1024 - 64)
			vars->balik.y +=15;
		else if (vars->balik.y + vars->balik.len_height < 1024 - 64)
			vars->balik.y += 1024 - 64 - vars->balik.y - vars->balik.len_height;
		
		mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
	}
	//left
	if (keycode == 123)
	{
		//clean_old_image(vars);
		if(vars->balik.y - 15 >  vars->img.len_height)
			vars->balik.y -= 15;
		else if (vars->balik.y > vars->img.len_height)
			vars->balik.y = vars->img.len_height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->balik.img_ptr,vars->balik.y,vars->balik.x );
	}
}

//keycode yakalama
//126 up
//124 right
//125 down
//123 left
// int	key_hook(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 		exit(0);

// }

t_vars create_img(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 1024, "Hello world!");
	return (vars);
}

t_vars background_color(char *img_path, t_vars vars)
{
	vars.background.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.background.img_width, &vars.background.len_height);
	vars.background.address = mlx_get_data_addr(vars.background.img_ptr, &vars.background.bits_per_pixel, &vars.background.line_size,
										 &vars.background.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 1024, 1024);

	return (vars);
}

t_vars create_img_a(char *img_path, t_vars vars,int nerde)
{
	vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.img.img_width, &vars.img.len_height);
	vars.img.address = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_size,
										 &vars.img.endian);
	for (int i = 0; i < 100; i++)
	{
		my_mlx_pixel_put(&vars.img, i	, 0, 0x0000FF);
	}
	
	printf("\n\n\nvar img %d %d \n\n",vars.img.len_height,vars.img.img_width);
	//x left
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, nerde * 64);
	//y up
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,  nerde * 64,0);
	//x right
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,960 , nerde * 64);
	// y down
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,  nerde * 64,960);
	return (vars);
}



t_vars  create_fish_img(char *img_path, t_vars vars, int yer)
{
	vars.balik.img_ptr = mlx_xpm_file_to_image(vars.mlx, img_path, &vars.balik.img_width, &vars.balik.len_height);
	vars.balik.address = mlx_get_data_addr(vars.balik.img_ptr, &vars.balik.bits_per_pixel, &vars.balik.line_size,
										 &vars.balik.endian);
	vars.balik.x = yer;
	vars.balik.y = 600;
		mlx_put_image_to_window(vars.mlx, vars.win, vars.balik.img_ptr,yer , 600);
		return (vars);
}
void start_draw(int fd, int kac_adim)
{
	char *read_data;
	int i;
	int x;
	int img_width, img_height;
	char *relative_path = "./teapot.xpm";
	char *balik_path = "./fish_monster.xpm";
	t_vars vars;
	int keycode; 
	int yer;

	yer = 600;
	x = 0;
	i = 1;
	printf("afhajs2f\n\n\n");
	vars = create_img(vars);
	while (i > 0)
	{
		i = get_next_line(fd, &read_data);

		printf("\n");
		x++;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("i = %d \n",i);
		vars = create_img_a(relative_path, vars,i);
	}
	vars = create_fish_img(balik_path,vars,yer);
	mlx_key_hook(vars.win,close_a,&vars);
	if (keycode == 126)
	{
		printf("	eglkaf\n\n");
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
