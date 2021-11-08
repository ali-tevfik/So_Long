/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/08 16:21:51 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	maps_load(char *read_data, t_vars vars, int x)
{
	int	a;

	a = 0;
	vars.maps[x] = ft_strdup(read_data);
	if (!vars.maps)
		exit_game(&vars);
	while (read_data[a])
	{
		if (read_data[a] == '1')
			create_walls(&vars, a, x);
		else if (read_data[a] == 'P')
			create_fish_img(&vars, a, x);
		else if (read_data[a] == 'C')
			create_collection(&vars, a, x);
		else if (read_data[a] == 'E')
			create_exit(&vars, a, x);
		a++;
	}
	return (vars);
}

void	start_draw(int fd, int step, int len)
{
	char	*read_data;
	int		i;
	int		x;
	t_vars	vars;

	vars.counter = 0;
	vars.maps = (char **) malloc(sizeof(vars.maps) * step);
	if (!vars.maps)
		exit_game(&vars);
	x = 0;
	i = 1;
	vars.game_speed = 64;
	vars.ate = 0;
	vars.total_eat = 0;
	create_win(&vars, len, step - 1);
	while (i > 0)
	{
		i = get_next_line(fd, &read_data);
		vars = maps_load(read_data, vars, x);
		x++;
	}
	vars.maps[x] = NULL;
	mlx_hook(vars.win, 2, 0, close_a, &vars);
	mlx_hook(vars.win, 17, 0, close_clikl, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	int	control_map;
	int	start_fd;
	int	step;
	int	len;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	control_map = check_len_maps(argc, argv, fd);
	if (control_map == -1)
		printf("Error Maps!\n");
	if (control_map == 0)
		control_map = check_maps(argv);
	if (control_map == -1)
		exit(0);
	step = step_find(argv);
	start_fd = open(argv[1], O_RDONLY);
	len = line_len(argv);
	start_draw(start_fd, step, len);
	 getchar();
}
