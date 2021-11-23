/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:21:20 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/23 15:25:56 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	maps_load(t_vars vars)
{
	int	a;
	int	x;

	x = 0;
	while (vars.map_info.maps[x])
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
	start_draw(data, &map_info);
	return (0);
}
