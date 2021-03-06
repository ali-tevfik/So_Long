/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_txt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 17:00:45 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/25 10:40:39 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	if (data)
		free(data);
}

int	check_chr(t_map maps, char **data)
{
	if (maps.player == 1 && maps.collection > 0 && maps.exit == 1)
		return (0);
	if (maps.player != 1)
		printf("Error Player!\n");
	if (maps.collection < 1)
		printf("Error Collection!\n");
	if (maps.exit != 1)
		printf("Error Exit!");
	free_data(data);
	exit(0);
}

int	result_check(int result, char **data)
{
	if (result == 0)
		return (0);
	printf("Error Maps!\n");
	free_data(data);
	exit(0);
}
