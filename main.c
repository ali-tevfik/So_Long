/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/12 11:27:30 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	maps_load(char *read_data, t_vars vars, int x)
{
	int	a;

	a = 0;
	vars.map_info.maps[x] = ft_strdup(read_data);
	if (!vars.map_info.maps)
		exit_game(&vars);
	while (read_data[a])
	{
		if (read_data[a] == '1')
			create_walls(&vars, a, x);
		else if (read_data[a] == 'P')
			create_player(&vars, a, x);
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

	vars.map_info.maps = (char **) malloc(sizeof(vars.map_info.maps) * step);
	if (!vars.map_info.maps)
		exit_game(&vars);
	x = 0;
	i = 1;
	vars.game_speed = 64;
	vars.ate = 0;
	vars.total_eat = 0;
	create_win(&vars, len, step - 3);
	while (i > 0)
	{
		i = get_next_line(fd, &read_data);
		vars = maps_load(read_data, vars, x);
		free(read_data);
		x++;
	}
	vars.map_info.maps[x] = NULL;
	mlx_hook(vars.win, 2, 0, click_button, &vars);
	mlx_hook(vars.win, 17, 0, close_clik, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	int		control_map;
	int		start_fd;
	t_map	map_info;
	int		fd;

	if (argc == 1)
	{
		printf("Please maps!\n");
		return (-1);
	}
	if (argc != 2)
	{
		printf("2 Maps Error\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	map_info = find_info_maps(argv);
	check_maps(argc, argv, fd, map_info.line);
	start_fd = open(argv[1], O_RDONLY);
	start_draw(start_fd, map_info.line + 2, map_info.len);
	return (0);
}
