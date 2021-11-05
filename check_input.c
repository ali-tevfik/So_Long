/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:07:36 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/05 19:09:53 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_maps(char *read_data, int step)
{
	int	control_map;
	int	i;

	i = 0;
	control_map = 0;
	if (step == 0)
		control_map = check_up_down(read_data);
	else
		control_map = check_left_right(read_data);
	while (control_map == 0 && read_data[i])
	{
		if (read_data[i] == '0' || read_data[i] == '1' || read_data[i] == 'C'
			|| read_data[i] == 'P' || read_data[i] == 'E')
			control_map = 0;
		else
			control_map = -1;
		i++;
	}
	return (control_map);
}

int	check_len_maps(int argc, char **argv, int fd)
{
	char	*read_data;
	int		step;
	int		len;
	int		control_map;

	control_map = 0;
	len = 0;
	step = 0;
	while (get_next_line(fd, &read_data) > 0)
	{
		if (step != 0)
		{
			if (len != ft_strlen(read_data))
				control_map = -1;
		}
		else
			len = ft_strlen(read_data);
		if (control_map == 0)
			control_map = check_line_maps(read_data, step);
		step++;
	}
	if (control_map == 0)
		control_map = check_line_maps(read_data, 0);
	return (control_map);
}

int	step_find(char **argv)
{
	char	*read_data;
	int		step;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	step = 0;
	while (get_next_line(fd, &read_data) > 0)
		step++;
	return (step);
}

int	line_len(char **argv)
{
	char	*read_data;
	int		step;
	int		fd;
	int		len;

	fd = open(argv[1], O_RDONLY);
	step = 0;
	get_next_line(fd, &read_data);
	len = ft_strlen(read_data);
	while (get_next_line(fd, &read_data) > 0)
	{
		free (read_data);
		step++;
	}
	return (len);
}

int	check_player(char **argv)
{
	char	*read_data;
	int		i;
	int		fd;
	int		counter;

	counter = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &read_data) > 0)
	{
		i = 0;
		while (read_data[i])
		{
			if (read_data[i] == 'P')
				counter++;
			i++;
		}
	}
	if (counter == 1)
		return (0);
	return (-1);
}
