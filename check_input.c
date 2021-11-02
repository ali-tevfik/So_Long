/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:07:36 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/02 17:55:31 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_maps(char *read_data, int step)
{
	int	control_map;

	control_map = 0;
	if (step == 0)
		control_map = check_up_down(read_data);
	else
		control_map = check_left_right(read_data);
	return (control_map);
}

int	check_len_maps(int argc, char **argv)
{
	int		fd;
	char	*read_data;
	int		step;
	int		len;
	int		control_map;

	control_map = 0;
	len = 0;
	step = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &read_data) > 0)
	{
		if (step != 0)
		{
			if (len != ft_strlen(read_data))
				control_map = -1;
		}
		else
			len = ft_strlen(read_data);
		if (check_line_maps(read_data, step) == -1 && control_map == 0)
			control_map = -1;
		step++;
	}
	if (check_line_maps(read_data, 0) == -1 && control_map == 0)
		control_map = -1;
	return (control_map);
}

int step_find(char **argv)
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

int line_len(char **argv)
{
	char *read_data;
	int step;
	int fd;

	fd = open(argv[1], O_RDONLY);
	step = 0;
	get_next_line(fd, &read_data);
	return (ft_strlen(read_data));
}
