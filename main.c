/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/23 14:29:46 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	maps_load(t_vars vars)
{
	int	a;
	int x;

	x  = 0;
	while(vars.map_info.maps[x])
	{
		a = 0;
		while (vars.map_info.maps[x][a])
		{
			if (vars.map_info.maps[x][a] == '1')
				create_walls(&vars, a, x);
			else if (vars.map_info.maps[x][a] == 'P')
				create_player(&vars, a, x);
			else if (vars.map_info.maps[x][a] == 'C')
				create_collection(&vars, a, x);
			else if (vars.map_info.maps[x][a] == 'E')
				create_exit(&vars, a, x);
			a++;
		}
		x++;
	}
	return (vars);
}

void	start_draw(char **data, t_map *maps_info)
{
	int		i;
	t_vars	vars;

	vars.game_speed = 64;
	vars.ate = 0;
	vars.total_eat = 0;
	vars.map_info.maps = data;
	create_win(&vars, maps_info->len, maps_info->line - 1);
	vars = maps_load(vars);
	mlx_hook(vars.win, 2, 0, click_button, &vars);
	mlx_hook(vars.win, 17, 0, close_clik, &vars);
	mlx_loop(vars.mlx);
}

void clean_old_data(char **new_data)
{
	int i;

	i = 0;
	while(new_data[i])
	{
		free(new_data[i]);
		i++;
	}
	if (new_data)
		free(new_data);
	exit(0);
}
char **load_data(char **argv, t_map map_info)
{
	char	**new_data;
	char	*read_data;
	int		i;
	int		fd;

	new_data = (char**)malloc(sizeof(new_data) * (map_info.line + 2));
	if (!new_data)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while(get_next_line(fd, &read_data) > 0)
	{
		if (!read_data)
			clean_old_data(new_data);
		new_data[i] = ft_strdup(read_data);
		if (!new_data)
		 	clean_old_data(new_data);
		i++;
		free(read_data);
	}
	free(read_data);
	new_data[i] = NULL;
	return (new_data);

}

int	main(int argc, char **argv)
{
	t_map	map_info;
	char	**data;

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
	map_info = find_info_maps(argv);
	data = load_data(argv, map_info);
	check_maps(data, map_info.line);
	start_draw( data, &map_info);
	return (0);
}
