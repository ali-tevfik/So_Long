/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/10/04 18:32:21 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

int close_a(int keycode, t_vars *vars)
{
	printf("\n\n\nHello from key_hook! %d vars mlx = %s win = %s\n", keycode, vars->mlx, vars->win);

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
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
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	return (vars);
}
void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char *dst;
	int offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
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
	
	
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, nerde * 20, nerde * 20);
	return (vars);
}
void start_draw(int fd, int kac_adim)
{
	char *read_data;
	int i;
	int x;
	int img_width, img_height;
	char *relative_path = "./teapot.xpm";
	t_vars vars;

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
	for (int i = 0; i < 50; i+=5)
	{
		printf("i = %d \n",i);
		vars = create_img_a(relative_path, vars,i);
	}
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
