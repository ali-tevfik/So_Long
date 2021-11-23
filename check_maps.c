/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_maps.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 16:37:31 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/23 15:27:33 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up_down(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_left_right(char *data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	if (data[0] == '1' && data[i - 1] == '1')
		return (0);
	return (-1);
}

void	check_line_chr(char **read_data, int step, int line)
{
	int	control_map;
	int	i;

	i = 0;
	control_map = 0;
	if (step == 0 || step == line - 1)
		control_map = check_up_down(*read_data);
	else
		control_map = check_left_right(read_data[step]);
	while (control_map == 0 && read_data[step][i])
	{
		if (read_data[step][i] == '0' || read_data[step][i] == '1'
			|| read_data[step][i] == 'C'
			|| read_data[step][i] == 'P' || read_data[step][i] == 'E')
			control_map = 0;
		else
			control_map = -1;
		i++;
	}
	check_map_len(control_map, read_data);
}

t_map	check_maps_chr(char *data, t_map maps)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == 'P')
			maps.player++;
		else if (data[i] == 'E')
			maps.exit++;
		else if (data[i] == 'C')
			maps.collection++;
		i++;
	}
	return (maps);
}

void	check_maps(char **data, int line)
{
	int		i;
	t_map	maps;
	int		len;
	int		result;

	maps.collection = 0;
	maps.exit = 0;
	maps.player = 0;
	i = 0;
	while (data[i])
	{
		maps = check_maps_chr(data[i], maps);
		check_line_chr(data, i, line);
		if (i == 0)
			len = ft_strlen(data[i]);
		else
			result = len - ft_strlen(data[i]);
		result_check(result, data);
		i++;
	}
	check_chr(maps, data);
}
