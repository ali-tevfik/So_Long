/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_txt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 17:00:45 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/12 11:28:22 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chr(t_map maps)
{
	if (maps.player == 1 && maps.collection > 0 && maps.exit == 1)
		return (0);
	if (maps.player != 1)
		printf("Error Player!\n");
	if (maps.collection < 1)
		printf("Error Collection!\n");
	if (maps.exit != 1)
		printf("Error Exit!");
	exit(0);
}

int	check_map_len(int i, char *data)
{
	if (i == 0)
		return (0);
	free(data);
	printf("Error Maps!\n");
	exit(0);
}

int	result_check(int result)
{
	if (result == 0)
		return (0);
	printf("Error Maps!\n");
	exit(0);
}
