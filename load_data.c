/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:03:21 by adoner        #+#    #+#                 */
/*   Updated: 2021/11/23 15:04:02 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_old_data(char **new_data)
{
	int	i;

	i = 0;
	while (new_data[i])
	{
		free(new_data[i]);
		i++;
	}
	if (new_data)
		free(new_data);
	exit(0);
}

char	**load_data(char **argv, t_map map_info)
{
	char	**new_data;
	char	*read_data;
	int		i;
	int		fd;

	new_data = (char **)malloc(sizeof(new_data) * (map_info.line + 2));
	if (!new_data)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &read_data) > 0)
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
