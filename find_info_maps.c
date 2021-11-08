/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_info_maps.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:07:36 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/08 21:20:29 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	find_info_maps(char **argv)
{
	char	*read_data;
	int		step;
	int		fd;
	t_map	map_info;

	fd = open(argv[1], O_RDONLY);
	step = 0;
	map_info.line = 0;
	while (get_next_line(fd, &read_data) > 0)
	{
		map_info.len = ft_strlen(read_data);
		free (read_data);
		map_info.line++;
	}
	free(read_data);
	return (map_info);
}
