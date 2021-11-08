/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_txt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 17:00:45 by catalina      #+#    #+#                 */
/*   Updated: 2021/11/08 16:21:18 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_txt(char *error_txt)
{
	printf("%s\n", error_txt);
}

int	check_error_and_write(t_map maps)
{
	if (maps.player == 1 && maps.collection > 0 && maps.exit == 1)
		return (0);
	if (maps.player != 1)
		printf("Error Player!\n");
	if (maps.collection < 1)
		printf("Error Collection!\n");
	if (maps.exit != 1)
		printf("Error Exit!");
	return (-1);
}
